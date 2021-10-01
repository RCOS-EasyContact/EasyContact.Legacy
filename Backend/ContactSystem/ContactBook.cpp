/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * ContactBook.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_CONTACTBOOK_CPP_
#define BACKEND_CONTACTSYSTEM_CONTACTBOOK_CPP_
// ContactSystem Header Files
#include "ContactBook.h"
bool BCS::ContactBook::addContact(const Contact &NewContact) {
  std::deque<Contact>::const_iterator R =
      std::find(_BOOK_SYSTEM.begin(), _BOOK_SYSTEM.end(), NewContact);
  if (R == _BOOK_SYSTEM.end()) {
    _BOOK_SYSTEM.push_front(NewContact);
    return true;
  }
  return false;
}
bool BCS::ContactBook::removeContact(const std::string &ExistContact) {
  std::deque<Contact>::iterator R =
      std::find(_BOOK_SYSTEM.begin(), _BOOK_SYSTEM.end(), ExistContact);
  if (R != _BOOK_SYSTEM.end()) {
    _BOOK_SYSTEM.erase(R);
    return true;
  }
  return false;
}
bool BCS::ContactBook::addTag(const std::string &TagName) {
  for (const std::pair<uint8_t, std::string> &Turple : _TAG_MAPPING) {
    if (Turple.second == TagName) {
      return false;
    }
  }
  return _TAG_MAPPING
      .insert(std::pair<uint8_t, std::string>(_TAG_MAPPING.size(), TagName))
      .second;
}
bool BCS::ContactBook::removeTag(const std::string &TagName) {
  for (std::map<uint8_t, std::string>::iterator Turple = _TAG_MAPPING.begin();
       Turple != _TAG_MAPPING.end(); Turple++) {
    if (Turple->second == TagName) {
      Turple->second.clear();
      return true;
    }
  }
  return false;
}
std::vector<BCS::Triple<std::string, std::string, std::vector<std::string>>>
BCS::ContactBook::getAllContacts() {}
#endif // BACKEND_CONTACTSYSTEM_CONTACTBOOK_CPP_