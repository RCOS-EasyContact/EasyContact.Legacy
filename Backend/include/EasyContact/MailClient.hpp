/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * MailClient.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_MAILCLIENT_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_MAILCLIENT_HPP_
// Resolve Conflict with LibBoost
#ifdef defer
#undef defer
#endif
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
#include <EasyContact/SysLogs.hpp>
namespace BMC {
 typedef MessageObj mailio::message;
bool AuthenticateLogin(const std::string& RCSID, const std::string& Password);
class MailClient {
 private:
  const std::string RCSID;
  const std::string Password;
  const std::string EmailAddress;
  mutable std::string Nickname;

 public:
  explicit MailClient(const std::string& _RCSID, const std::string& _Password);
  explicit MailClient(const std::string& _RCSID, const std::string& _Password,
                      const std::string& _Nickname, const std::string& _Email);
  // recv email, if no error, the return should be the a message;
  bool Fetch(const size_t& NumEmails) const;
  bool recv(MessageObj* mesg) const;
  bool remove_first() const;
  int inbox_status() const;
  int sent_message(const std::string& name_to, const std::string& to_mail,
                   const std::string& subjects, const std::string& mesg) const;
};
}  // namespace BMC
#endif  // BACKEND_INCLUDE_EASYCONTACT_MAILCLIENT_HPP_
