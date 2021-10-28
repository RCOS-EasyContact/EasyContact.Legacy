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
    std::cerr << "Run-Time Exception: SQLite" << std::endl;
    std::cerr << Err.what() << std::endl;
    return false;
  }
}
#endif  // BACKEND_SQLCONTACTS_CONTACTS_CPP_