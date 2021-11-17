/**
 * RCOS-EasyContact
 * EasyContact/Backend/src
 * MailClient.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SRC_MAILCLIENT_CPP_
#define BACKEND_SRC_MAILCLIENT_CPP_
#include <EasyContact/MailClient.hpp>
static const char* const UserDataLocation = "data/";
static const char* const EmailServerAddress = "mail.rpi.edu";
static const uint16_t IMAP_PORT = 993;
static const uint16_t SMTP_PORT = 587;
static const uint16_t IMAP_NONSSL_PORT = 143;
bool BMC::AuthenticateLogin(const std::string& RCSID,
                            const std::string& Password) {
  try {
    mailio::imaps Auth(EmailServerAddress, IMAP_PORT);
    Auth.authenticate(RCSID, Password, mailio::imaps::auth_method_t::LOGIN);
  } catch (const std::exception&) {
    return false;
  }
  return true;
}
BMC::MailClient::MailClient(const std::string& _RCSID,
                            const std::string& _Password)
    : RCSID(_RCSID),
      Password(_Password),
      EmailAddress(_RCSID + "@rpi.edu"),
      Nickname(_RCSID) {}
size_t BMC::MailClient::InboxEmails() const {
  size_t Result = 0;
  try {
    mailio::imaps IMAP(EmailServerAddress, IMAP_PORT);
    IMAP.authenticate(RCSID, Password, mailio::imaps::auth_method_t::LOGIN);
    mailio::imaps::mailbox_stat_t STAT = IMAP.statistics("Inbox");
    Result = STAT.messages_no;
  } catch (const mailio::imap_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const mailio::dialog_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
  }
  return Result;
}
bool BMC::MailClient::RecvEmail(const size_t& ID, mailio::message* M) const {
  try {
    M->line_policy(mailio::codec::line_len_policy_t::VERYLARGE,
                   mailio::codec::line_len_policy_t::VERYLARGE);
    mailio::imaps IMAP(EmailServerAddress, IMAP_PORT);
    IMAP.authenticate(RCSID, Password, mailio::imaps::auth_method_t::LOGIN);
    IMAP.fetch("Inbox", ID, *M);
    return true;
  } catch (const mailio::imap_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const mailio::dialog_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
  }
  return false;
}
bool BMC::MailClient::RemoveEmail(const size_t& ID) {
  try {
    mailio::imaps IMAP(EmailServerAddress, IMAP_PORT);
    IMAP.authenticate(RCSID, Password, mailio::imaps::auth_method_t::LOGIN);
    IMAP.remove("Inbox", ID);
    return true;
  } catch (const mailio::imap_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const mailio::dialog_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
  }
  return false;
}
void BMC::MailClient::ChangeNickname(const std::string& _Nickname) noexcept {
  Nickname = _Nickname;
}
bool BMC::MailClient::Fetch(const size_t& NumEmails) const {
  const size_t TotalEmails = InboxEmails();
  size_t NumToFetch = TotalEmails;
  if (NumToFetch >= NumEmails) {
    NumToFetch = NumEmails;
  }
  for (size_t i = 0; i < NumToFetch; ++i) {
    const size_t Current_ID = TotalEmails - i;
    mailio::message M;
    if (RecvEmail(Current_ID, &M) == false) {
      return false;
    }
    std::ofstream FILE;
    FILE.open(std::string(UserDataLocation) + RCSID + "/" + std::to_string(i) +
              ".txt");
    FILE << "Subject: " << M.subject() << std::endl;
    FILE << "From: " << M.from_to_string() << std::endl;
    FILE << "Content: " << M.content() << std::endl;
    FILE.close();
  }
  return false;
}
bool BMC::MailClient::SendMessage(const std::string& Recipient_Name,
                                  const std::string& Recipient_Email,
                                  const std::string& Subject,
                                  const std::string& Messagebody) const {
  try {
    mailio::smtps SMTP(EmailServerAddress, SMTP_PORT);
    SMTP.authenticate(RCSID, Password, mailio::smtps::auth_method_t::START_TLS);
    mailio::message M;
    M.from(mailio::mail_address(Nickname, EmailAddress));
    M.add_recipient(mailio::mail_address(Recipient_Name, Recipient_Email));
    M.subject(Subject);
    M.content(Messagebody);
    SMTP.submit(M);
    return true;
  } catch (const mailio::smtp_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const mailio::dialog_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
  }
  return false;
}
#endif  // BACKEND_SRC_MAILCLIENT_CPP_
