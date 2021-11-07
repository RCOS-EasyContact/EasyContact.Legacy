/**
 * RCOS-EasyContact
 * EasyContact/Backend/MailClient
 * MailClient.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_MAILCLIENT_MAILCLIENT_HPP_
#define BACKEND_MAILCLIENT_MAILCLIENT_HPP_
// C++ Standard Library
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
// MailIO Header Files
#include <mailio/imap.hpp>
#include <mailio/message.hpp>
#include <mailio/smtp.hpp>
// EasyContact Header Files
#include "../Executable/SysLogs.hpp"
namespace BMC {
static bool AuthenticateLogin(const std::string& RCSID, const std::string& Password){
  try {
    mailio::imaps conn("mail.rpi.edu", 993);
    conn.authenticate(RCSID, Password, mailio::imaps::auth_method_t::LOGIN);
  } catch (const mailio::imap_error& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
class MailClient {
 private:
  const std::string RCSID;
  const std::string Password;
  const std::string usr_email;
  mutable std::string usr_name;

 public:
  explicit MailClient(const std::string& _RCSID, const std::string& _Password)
      : RCSID(_RCSID),
        Password(_Password),
        usr_email(_RCSID + "@rpi.edu"),
        usr_name(_RCSID) {}
  explicit MailClient(const std::string& _RCSID, const std::string& _Password,
                      const std::string& _Nickname, const std::string& _Email)
      : RCSID(_RCSID),
        Password(_Password),
        usr_name(_Nickname),
        usr_email(_Email) {}
  // recv email, if no error, the return should be the a message;
  int recv(mailio::message* mesg);
  int remove_first();
  int inbox_status();
  int sent_message(const std::string& name_to, const std::string& to_mail,
                   const std::string& subjects, const std::string& mesg);
};
}  // namespace BMC
#endif  // BACKEND_MAILCLIENT_MAILCLIENT_HPP_
