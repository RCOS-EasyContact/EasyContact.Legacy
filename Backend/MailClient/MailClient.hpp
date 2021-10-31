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
using namespace mailio;
namespace BMC {
bool AuthenticateLogin(const std::string& RCSID, const std::string& Password);
class MailClient {
 private:
  std::string RCSID;
  std::string Password;
  std::string usr_name;
  std::string usr_email;

 public:
  // constructor
  explicit MailClient(const std::string& RCSID, const std::string& Password,
                      const std::string& usr_name, const std::string& usr_email);
  // recv email, if no error, the return should be the a message;
  int recv(message* mesg);
  int remove_first();
  int inbox_status();
  int sent_message(const std::string& name_to, const std::string& to_mail,
                   const std::string& subjects, const std::string& mesg);
};
}  // namespace BMC
#endif  // BACKEND_MAILCLIENT_MAILCLIENT_HPP_
