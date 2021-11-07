/**
 * RCOS-EasyContact
 * EasyContact/Backend/SQLContacts
 * Contacts.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SQLCONTACTS_CONTACTS_HPP_
#define BACKEND_SQLCONTACTS_CONTACTS_HPP_
// SQL Lite Library
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/VariadicBind.h>
// C++ Standard Library
#include <filesystem>
#include <string>
// Standard Template Library
#include <vector>
// EasyContact Header Files
#include "../Executable/SysLogs.hpp"
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
static void CreateDirectory(const std::string &DirName){
   if (!std::filesystem::directory_entry("UserData/" + DirName).is_directory()) {
    std::filesystem::create_directory("UserData/" + DirName);
    copy_file(
        std::filesystem::directory_entry("UserData/.DEFAULT/Contacts.db3"),
        std::filesystem::directory_entry("UserData/" + DirName +
                                         "/Contacts.db3"));
  }
}
class Contacts {
  const std::string RCSID;

 public:
  explicit Contacts(const std::string &newRCSID) : RCSID(newRCSID) {
    CreateDirectory(RCSID);
  }
  bool newContact(const std::string &Name, const std::string &Email);
  bool newTag(const std::string &TagName);
  bool removeContact(const std::string &Name);
  bool removeTag(const std::string &TagName);
  std::string getEmailAddress(const std::string &Name) const;
  std::vector<std::string> getAllNames() const;
  std::vector<std::string> getAllTags() const;
  std::vector<std::string> getTagContains(const std::string &TagName) const;
  void assignTagTo(const std::string &TagName, const std::string &ContactName);
  void removeTagFor(const std::string &TagName, const std::string &ContactName);
};
}  // namespace BCS
#endif  // BACKEND_SQLCONTACTS_CONTACTS_HPP_
