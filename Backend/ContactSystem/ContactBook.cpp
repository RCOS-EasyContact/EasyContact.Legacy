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
#endif // BACKEND_CONTACTSYSTEM_CONTACTBOOK_CPP_