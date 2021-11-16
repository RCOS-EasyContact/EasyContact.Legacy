/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * Contacts.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
// SQL Lite Library
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/VariadicBind.h>
// C++ Standard Library
#include <filesystem>
#include <string>
// Standard Template Library
#include <vector>
// EasyContact Header Files
#include <EasyContact/SysLogs.hpp>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
void CreateDirectory(const std::string &DirName)noexcept;
class Contacts {
 private:
  const std::string RCSID;

 public:
  explicit Contacts(const std::string &newRCSID);
  bool newContact(const std::string &Name, const std::string &Email);
  bool newTag(const std::string &TagName);
  bool removeContact(const std::string &Name);
  bool removeTag(const std::string &TagName);
  [[nodiscard]] std::string getEmailAddress(const std::string &Name) const;
  [[nodiscard]] std::vector<std::string> getAllNames() const;
  [[nodiscard]] std::vector<std::string> getAllTags() const;
  [[nodiscard]] std::vector<std::string> getTagContains(const std::string &TagName) const;
  bool assignTagTo(const std::string &TagName, const std::string &ContactName);
  bool removeTagFor(const std::string &TagName, const std::string &ContactName);
};
}  // namespace BCS
#endif  // BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
