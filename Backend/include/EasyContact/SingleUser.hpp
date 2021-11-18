/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * SingleUser.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_SINGLEUSER_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_SINGLEUSER_HPP_
// C++ Standard Library
#include <string>
// EasyContact Header Files
#include <EasyContact/Contacts.hpp>
#include <EasyContact/MailClient.hpp>
class SingleUser : public BCS::Contacts, public BMC::MailClient {
 public:
  explicit SingleUser(const std::string& RCSID, const std::string& Password);
};
#endif  // BACKEND_INCLUDE_EASYCONTACT_SINGLEUSER_HPP_
