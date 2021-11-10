/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * SingleUser.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_EXECUTABLE_SINGLEUSER_HPP_
#define BACKEND_EXECUTABLE_SINGLEUSER_HPP_
// C++ Standard Library
#include <string>
// EasyContact Header Files
#include "../MailClient/MailClient.hpp"
#include "../SQLContacts/Contacts.hpp"
class SingleUser {
 public:
  BMC::MailClient MailClient;
  BCS::Contacts SQLContacts;
  explicit SingleUser(const std::string& RCSID, const std::string& Password);
};
SingleUser::SingleUser(const std::string& RCSID, const std::string& Password)
    : MailClient(RCSID, Password), SQLContacts(RCSID) {}
#endif  // BACKEND_EXECUTABLE_SINGLEUSER_HPP_
