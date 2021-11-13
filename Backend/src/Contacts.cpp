/**
 * RCOS-EasyContact
 * EasyContact/Backend/src
 * Contacts.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SRC_CONTACTS_CPP_
#define BACKEND_SRC_CONTACTS_CPP_
#include <EasyContact/Contacts.hpp>
const static char* UserDataLocation = "data/";
void BCS::CreateDirectory(const std::string& DirName) {
  if (!std::filesystem::directory_entry("" + UserDataLocation + DirName)
           .is_directory()) {
    std::filesystem::create_directory("" + UserDataLocation + DirName);
    copy_file(std::filesystem::directory_entry("" + UserDataLocation +
                                               ".DEFAULT/Contacts.db3"),
              std::filesystem::directory_entry("" + UserDataLocation + DirName +
                                               "/Contacts.db3"));
  }
}
BCS::Contacts::Contacts(const std::string& newRCSID) : RCSID(newRCSID) {
  CreateDirectory(RCSID);
}
bool BCS::Contacts::newContact(const std::string& Name,
                               const std::string& Email) {
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3",
                         SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    SQLite::Statement Query(DB3, "INSERT INTO emailadres SELECT ?,?");
    Query.bind(1, Name);
    Query.bind(2, Email);
    Query.exec();
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
bool BCS::Contacts::newTag(const std::string& TagName) {
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3",
                         SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    {
      SQLite::Statement Query(DB3, "INSERT INTO tags SELECT ?");
      Query.bind(1, TagName);
      Query.exec();
    }
    const std::string NewTableName = "tag_" + TagName;
    SQLite::Statement Query(DB3,
                            "CREATE TABLE " + NewTableName +
                                " (RCSID TEXT NOT NULL PRIMARY KEY REFERENCES "
                                "emailadres(RCSID) ON DELETE CASCADE)");
    Query.exec();
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
bool BCS::Contacts::removeContact(const std::string& Name) {
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3",
                         SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    SQLite::Statement Query(DB3, "DELETE FROM emailadres WHERE RCSID=?");
    Query.bind(1, Name);
    Query.exec();
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
bool BCS::Contacts::removeTag(const std::string& TagName) {
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3",
                         SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    SQLite::Statement Query(DB3, "DROP TABLE " + TagName);
    Query.exec();
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
std::string BCS::Contacts::getEmailAddress(const std::string& Name) const {
  std::string Result;
  try {
    std::vector<std::string> Buffer;
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3");
    SQLite::Statement Query(DB3, "SELECT Email FROM emailadres WHERE RCSID=?");
    Query.bind(1, Name);
    while (Query.executeStep()) {
      Buffer.push_back(Query.getColumn(0));
    }
    Result = Buffer.front();
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
  }
  return Result;
}
std::vector<std::string> BCS::Contacts::getAllNames() const {
  std::vector<std::string> Result;
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3");
    SQLite::Statement Query(DB3, "SELECT RCSID FROM emailadres");
    while (Query.executeStep()) {
      Result.push_back(Query.getColumn(0));
    }
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
  }
  return Result;
}
std::vector<std::string> BCS::Contacts::getAllTags() const {
  std::vector<std::string> Result;
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3");
    SQLite::Statement Query(DB3, "SELECT * FROM tags");
    while (Query.executeStep()) {
      Result.push_back(Query.getColumn(0));
    }
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
  }
  return Result;
}
std::vector<std::string> BCS::Contacts::getTagContains(
    const std::string& TagName) const {
  std::vector<std::string> Result;
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3");
    const std::string TableTagName = "tag_" + TagName;
    SQLite::Statement Query(DB3, "SELECT * FROM " + TableTagName);
    while (Query.executeStep()) {
      Result.push_back(Query.getColumn(0));
    }
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
  }
  return Result;
}
bool BCS::Contacts::assignTagTo(const std::string& TagName,
                                const std::string& ContactName) {
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3",
                         SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    const std::string TableTagName = "tag_" + TagName;
    SQLite::Statement Query(DB3, "INSERT INTO " + TableTagName + " SELECT ?");
    Query.bind(1, ContactName);
    Query.exec();
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
bool BCS::Contacts::removeTagFor(const std::string& TagName,
                                 const std::string& ContactName) {
  try {
    SQLite::Database DB3(UserDataLocation + RCSID + "/Contacts.db3",
                         SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    const std::string TableTagName = "tag_" + TagName;
    SQLite::Statement Query(DB3,
                            "DELETE FROM " + TableTagName + " WHERE RCSID=?");
    Query.bind(1, ContactName);
    Query.exec();
  } catch (const std::exception& Err) {
    SYSLOG::PrintException(Err);
    return false;
  }
  return true;
}
#endif  // BACKEND_SRC_CONTACTS_CPP_
