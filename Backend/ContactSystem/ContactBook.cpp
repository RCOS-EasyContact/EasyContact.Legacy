/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * ContactBook.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_CONTACTBOOK_CPP_
#define BACKEND_CONTACTSYSTEM_CONTACTBOOK_CPP_
#include "ContactBook.h"
ssize_t BCS::ContactBook::__H_ExistsGroup(const std::string &GroupName) {
  for (size_t i = 0; i < _BOOKS.size(); i++) {
    if (_BOOKS[i].getGroupName() == GroupName) {
      return (ssize_t)i;
    }
  }
  return (ssize_t)-1;
}
bool BCS::ContactBook::addNewGroup(const std::string &GroupName) {
  const ssize_t GroupIndex = __H_ExistsGroup(GroupName);
  if (GroupIndex == -1) {
    _BOOKS.push_back(GroupContact(GroupName));
    return true;
  }
  return false;
}
bool BCS::ContactBook::addNewContact(const std::string &GroupName,
                                     const BCS::Contact &NewContact) {
  const ssize_t GroupIndex = __H_ExistsGroup(GroupName);
  if (GroupIndex != -1) {
    return _BOOKS[GroupIndex].addNewContact(NewContact);
  }
  return false;
}
BCS::GroupContact &BCS::ContactBook::operator[](const uint64_t &GroupIndex) {
  try {
    if (GroupIndex >= _BOOKS.size()) {
      throw GroupIndex;
    }
  } catch (uint64_t Exception) {
    std::cerr << "Caught Runtime Exception" << std::endl;
    std::cerr << "ContactBook: "
              << "Request Index: " << Exception << " OUT-OF-BOUNDS"
              << std::endl;
  }
  return _BOOKS[GroupIndex];
}
#endif  // BACKEND_CONTACTSYSTEM_CONTACTBOOK_CPP_
