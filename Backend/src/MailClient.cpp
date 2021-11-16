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
bool BMC::AuthenticateLogin(const std::string& RCSID,
                            const std::string& Password) {
  try {
    mailio::imaps Auth(EmailServerAddress, IMAP_PORT);
    Auth.authenticate(RCSID, Password, mailio::imaps::auth_method_t::START_TLS);
  } catch (const mailio::imap_error& Err) {
    SYSLOG::PrintException(Err);
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
bool BMC::MailClient::RecvEmail(const size_t& ID, MessageObj* M) const {
  try {
    M->line_policy(mailio::codec::line_len_policy_t::RECOMMENDED,
                   mailio::codec::line_len_policy_t::RECOMMENDED);
    mailio::imaps IMAP(EmailServerAddress, IMAP_PORT);
    IMAP.authenticate(RCSID, Password, mailio::imaps::auth_method_t::START_TLS);
    IMAP.fetch(ID, *M);
    return true;
  } catch (const mailio::imap_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const mailio::dialog_error& Err) {
    SYSLOG::PrintException(Err);
  }
  return false;
}
void BMC::MailClient::ChangeNickname(const std::string& _Nickname) noexcept {
  Nickname = _Nickname;
}
bool BMC::MailClient::Fetch(const size_t& NumEmails) const {
  mailio::imaps IMAP(EmailServerAddress, IMAP_PORT);
  IMAP.authenticate(RCSID, Password, mailio::imaps::auth_method_t::START_TLS);
  const size_t TotalEmails =
      IMAP.select(std::list<std::string>({"Inbox"})).messages_no;
  size_t NumToFetch = TotalEmails;
  if (NumToFetch >= NumEmails) {
    NumToFetch = NumEmails;
  }
  for (size_t i = 0; i < NumToFetch; ++i) {
    const size_t Current_ID = TotalEmails - i;
    MessageObj M;
    if (RecvEmail(Current_ID, &M) == false) {
      return false;
    }
    std::ofstream FILE;
    FILE.open(std::string(UserDataLocation) + RCSID + "/" +
              std::to_string(Current_ID) + ".txt");
    FILE << "Subject: " << M.subject() << std::endl;
    FILE << "From: " << M.from_to_string() << std::endl;
    FILE << "Content: " << M.content() << std::endl;
    FILE.close();
  }
  return false;
}
bool BMC::MailClient::RemoveEmail(const size_t& ID) {
  try {
    mailio::imaps IMAP(EmailServerAddress, IMAP_PORT);
    IMAP.authenticate(RCSID, Password, mailio::imaps::auth_method_t::START_TLS);
    IMAP.remove("Inbox", ID);
    return true;
  } catch (const mailio::imap_error& Err) {
    SYSLOG::PrintException(Err);
  } catch (const mailio::dialog_error& Err) {
    SYSLOG::PrintException(Err);
  }
  return false;
}
#if 0
int BMC::MailClient::inbox_status() const {
  int ret = 0;
  try {
    // connect to server
    imaps conn("mail.rpi.edu", 993);
    // modify to use an existing zoho account
    conn.authenticate(RCSID, Password, imaps::auth_method_t::LOGIN);
    // query inbox statistics
    imaps::mailbox_stat_t stat = conn.statistics("inbox");
    ret = stat.messages_no;
  } catch (const imap_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  } catch (const dialog_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return ret;
}
#endif
bool BMC::MailClient::SendMessage(const std::string& Recipient_Name,
                                  const std::string& Recipient_Email,
                                  const std::string& Subject,
                                  const std::string& Messagebody) const {
  try {
    mailio::smtps SMTP(EmailServerAddress, SMTP_PORT);
    SMTP.authenticate(RCSID, Password, mailio::smtps::auth_method_t::START_TLS);
    MessageObj M;
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
  }
  return false;
}
#endif  // BACKEND_SRC_MAILCLIENT_CPP_
