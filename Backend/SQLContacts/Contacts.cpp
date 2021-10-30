/**
 * RCOS-EasyContact
 * EasyContact/Backend/SQLContacts
 * Contacts.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SQLCONTACTS_CONTACTS_CPP_
#define BACKEND_SQLCONTACTS_CONTACTS_CPP_
#include "Contacts.hpp"
void BCS::CreateDirectory(const std::string& DirName) {
  if (!std::filesystem::directory_entry("UserData/" + DirName).is_directory()) {
    std::filesystem::create_directory("UserData/" + DirName);
    copy_file(
        std::filesystem::directory_entry("UserData/.DEFAULT/Contacts.db3"),
        std::filesystem::directory_entry("UserData/" + DirName +
                                         "/Contacts.db3"));
  }
}
bool BCS::Contacts::newContact(const std::string& Name,
                               const std::string& Email) {
  try {
  SQLite::Database DB3("UserData/" + RCSID + "/Contacts.db3",
                       SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
   SQLite::Statement Query(DB3,"INSERT INTO emailadres SELECT '?','?'");
   Query.bind(0,Name);
   Query.bind(1,Email);
   Query.exec();

  } catch (std::exception& Err) {
    std::cerr << "Run-Time Exception <SQLite> : " << Err.what() << std::endl;
    return false;
  }
    return true;
}
void BCS::Contacts::newTag(const std::string& TagName) {
  SQLite::Database DB3("UserData/" + RCSID + "/Contacts.db3",
                       SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
  try {
    DB3.exec("CREATE TABLE tag_" + TagName + "(RCSID TEXT PRIMARY KEY)");
    DB3.exec("INSERT INTO tags SELECT '" + TagName + "'");
  } catch (std::exception& Err) {
    std::cerr << "Run-Time Exception <SQLite> : " << Err.what() << std::endl;
  }
}
std::vector<std::string> BCS::Contacts::getAllTags() const {
  std::vector<std::string> Result;
  SQLite::Database DB3("UserData/" + RCSID + "/Contacts.db3");
  try {
    SQLite::Statement Query(DB3, "SELECT * FROM tags");
    while (Query.executeStep()) {
      Result.push_back(Query.getColumn(0));
    }
  } catch (std::exception& Err) {
    std::cerr << "Run-Time Exception <SQLite> : " << Err.what() << std::endl;
  }
  return Result;
}
#endif  // BACKEND_SQLCONTACTS_CONTACTS_CPP_
