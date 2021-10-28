/**
 * RCOS-EasyContact
 * EasyContact/Backend/SQLContacts
 * Contacts.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SQLCONTACTS_CONTACTS_CPP_
#define BACKEND_SQLCONTACTS_CONTACTS_CPP_
#include "Contacts.hpp"
bool BCS::Contacts::newContact(const std::string& Name, const std::string& Email){
  SQLite::Database    DB3("UserData/"+RCSID+"/Contacts.db3",SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
  SQLite::Statement   Query(DB3, "INSERT INTO emailadres SELECT");
}
#endif // BACKEND_SQLCONTACTS_CONTACTS_CPP_