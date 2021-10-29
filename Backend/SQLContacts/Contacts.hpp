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
#include <vector>
// SQL Lite Library
#include <SQLiteCpp.h>
#include <VariadicBind.h>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
void CreateDirectory(const std::string &DirName);
class Contacts {
  const std::string RCSID;

 public:
  explicit Contacts(const std::string &newRCSID) : RCSID(newRCSID) {
    CreateDirectory(RCSID);
  }
  bool newContact(const std::string &Name, const std::string &Email);
  void newTag(const std::string &TagName);
  bool removeContact(const std::string &ExistContact);
  bool removeTag(const std::string &TagName);
  [[nodiscard]] std::vector<std::string> getAllContacts() const;
  [[nodiscard]] std::vector<std::string> getAllTags() const;
  [[nodiscard]] std::vector<std::string> getTagContains(const std::string &TagName) const;
  [[nodiscard]] std::vector<std::string> getNameInTags(const std::string &ContactName) const;
  void assignTagTo(const std::string &TagName, const std::string &ContactName);
  void removeTagFor(const std::string &TagName, const std::string &ContactName);
  void clearTagFor(const std::string &ContactName);
};
}  // namespace BCS
#endif  // BACKEND_SQLCONTACTS_CONTACTS_HPP_
