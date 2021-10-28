/**
 * RCOS-EasyContact
 * EasyContact/Backend/SQLContacts
 * Contacts.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SQLCONTACTS_CONTACTS_HPP_
#define BACKEND_SQLCONTACTS_CONTACTS_HPP_
// C++ Standard Library
#include <exception>
#include <filesystem>
#include <iostream>
#include <string>
// Standard Template Library
#include <memory>
#include <vector>
// SQL Lite Library
#include <SQLiteCpp.h>
#include <VariadicBind.h>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
class Contacts {
 void CreateDirectory();
 public:
  const std::string RCSID;
  explicit Contacts(const std::string& newRCSID) : RCSID(newRCSID) {
    CreateDirectory();
  }
  /**
   * Add New Contact
   * Duplicate Contacts Are Not Allowed
   * @param <BCS::Key> : Contact Name
   * @return <bool> : Success or Failed (Existing Contact)
   */
  bool newContact(const std::string& Name, const std::string& Email);
  void newTag(const std::string& TagName);
  std::vector<std::string> getAllTags() const;
};
}  // namespace BCS
#endif  // BACKEND_SQLCONTACTS_CONTACTS_HPP_
