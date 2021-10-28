/**
 * RCOS-EasyContact
 * EasyContact/Backend/SQLContacts
 * Contacts.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SQLCONTACTS_CONTACTS_CPP_
#define BACKEND_SQLCONTACTS_CONTACTS_CPP_
#include "Contacts.hpp"
bool BCS::Contacts::newContact(const std::string& Name,
                               const std::string& Email) {
  SQLite::Database DB3("UserData/" + RCSID + "/Contacts.db3",
                       SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
  try {
    DB3.exec("INSERT INTO emailadres SELECT '" + Name + "','" + Email + "'");
    return true;
  } catch (std::exception& Err) {
    std::cerr << "Run-Time Exception <SQLite> :" << std::endl;
    std::cerr << Err.what() << std::endl;
    return false;
  }
}
void BCS::Contacts::newTag(const std::string& TagName) {
  SQLite::Database DB3("UserData/" + RCSID + "/Contacts.db3",
                       SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
  try {
    DB3.exec("CREATE TABLE tag_" + TagName + "(RCSID TEXT PRIMARY KEY)");
  } catch (std::exception& Err) {
    std::cerr << "Run-Time Exception <SQLite> :" << std::endl;
    std::cerr << Err.what() << std::endl;
  }
  std::vector<std::string> BCS::Contacts::getAllTags()const{
    std::vector<std::string> Result;
    SQLite::Database DB3("UserData/"+RCSID+"Contacts.db3");
SQLite::Statement Query(DB3, "SELECT TABLE_NAME FROM PUBLIC.TABLES WHERE TABLE_TYPE='BASE TABLE'");
while(Query.executeSetp()){
  Result.push_back(Query.getColumn(0));
  }
  return Result;
  }
}
#endif  // BACKEND_SQLCONTACTS_CONTACTS_CPP_
