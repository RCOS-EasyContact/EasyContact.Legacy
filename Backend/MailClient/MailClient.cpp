/**
 * RCOS-EasyContact
 * EasyContact/Backend/MailClient
 * MailClient.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_MAILCLIENT_MAILCLIENT_CPP_
#define BACKEND_MAILCLIENT_MAILCLIENT_CPP_
#include "MailClient.hpp"
using mailio::codec;
using mailio::dialog_error;
using mailio::imap;
using mailio::imap_error;
using mailio::imaps;
using mailio::mail_address;
using mailio::message;
using mailio::smtp_error;
using mailio::smtps;
bool BCS::AuthenticateLogin(const std::string& RCSID,
                              const std::string& Password) {
  try {
    mailio::imaps conn("mail.rpi.edu", 993);
    conn.authenticate(RCSID, Password, mailio::imaps::auth_method_t::LOGIN);
  } catch (const mailio::imap_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
int BMC::MailClient::recv(message* msg) {
  // message &new_msg = *msg;
  try {
    imaps conn("mail.rpi.edu", 993);
    conn.authenticate(RCSID, Password, imaps::auth_method_t::LOGIN);
    imaps::mailbox_stat_t ret = conn.select(std::list<std::string>({"Inbox"}));
    msg->line_policy(codec::line_len_policy_t::VERYLARGE,
                     codec::line_len_policy_t::VERYLARGE);
    conn.fetch(ret.messages_no, *msg);
    /*
            std::cout<<msg.subject()<<std::endl;
            std::cout<<msg.content()<<std::endl;
            std::cout<<msg.from_to_string()<<std::endl;from who
    */
  } catch (const imap_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  } catch (const dialog_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
int BMC::MailClient::remove_first() {
  try {
    imap conn("mail.rpi.edu", 143);
    conn.authenticate(RCSID, Password, imap::auth_method_t::LOGIN);
    conn.remove("inbox", 1);
  } catch (const imap_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  } catch (const dialog_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
int BMC::MailClient::inbox_status() {
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
int BMC::MailClient::sent_message(const std::string& name_to,
                                  const std::string& to_mail,
                                  const std::string& subjects,
                                  const std::string& mesg) {
  try {
    message msg;
    msg.from(mail_address(usr_name,
                          usr_email));  // mail_adddress(name,xxx@xxx.edu(com))
    msg.add_recipient(mail_address(name_to, to_mail));
    msg.subject(subjects);
    msg.content(mesg);

    smtps conn("mail.rpi.edu", 587);
    conn.authenticate(RCSID, Password, smtps::auth_method_t::START_TLS);
    conn.submit(msg);
  } catch (const smtp_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  } catch (const dialog_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
#endif  // BACKEND_MAILCLIENT_MAILCLIENT_CPP_
