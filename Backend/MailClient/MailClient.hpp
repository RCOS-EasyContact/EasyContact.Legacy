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

using namespace std;
using namespace mailio;

namespace BMC {
bool AuthenticateLogin(const std::string& RCSID, const std::string& Password);
class MailClient {
 private:
  string RCSID;
  string Password;
  string usr_name;
  string usr_email;

 public:
  // constructor
  explicit MailClient(const string& RCSID, const string& Password,
                      const string& usr_name, const string& usr_email);
  // recv email, if no error, the return should be the a message;
  int recv(message* mesg);
  int remove_first();
  int inbox_status();
  int sent_message(const string& name_to, const string& to_mail,
                   const string& subjects, const string& mesg);
};
}  // namespace BMC
#endif  // BACKEND_MAILCLIENT_MAILCLIENT_HPP_
