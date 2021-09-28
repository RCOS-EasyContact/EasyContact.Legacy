/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * ContactBook.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_
#define BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_
#include "GroupContact.h"
#include <iostream>
#include <string>
#include <vector>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
class ContactBook {
  std::vector<GroupContact> _BOOKS;
  inline ssize_t __H_ExistsGroup(const std::string &GroupName);
  static GroupContact _NULL;

 public:
  ContactBook() = default;
  const GroupContact &getGroup(const std::string &GroupName) {
    return _BOOKS[__H_ExistsGroup(GroupName)];
  }
  bool addNewGroup(const std::string &GroupName) {
    const ssize_t GroupIndex = __H_ExistsGroup(GroupName);
    if (GroupIndex == -1) {
      _BOOKS.push_back(GroupContact(GroupName));
      return true;
    }
    return false;
  }
  bool addNewContact(const std::string &GroupName, const Contact &NewContact) {
    const ssize_t GroupIndex = __H_ExistsGroup(GroupName);
    if (GroupIndex != -1) {
      return _BOOKS[GroupIndex].addNewContact(NewContact);
    }
    return false;
  }
  friend std::ostream &operator<<(std::ostream &FILE,
                                  const ContactBook &Input) {
    for (const GroupContact &N : Input._BOOKS) {
      FILE << N << " | ";
    }
    return FILE;
  }
  inline bool operator+=(const std::string &GroupName) {
    return this->addNewGroup(GroupName);
  }
  GroupContact &operator[](const uint64_t &GroupIndex) {
    if (GroupIndex < _BOOKS.size()) {
      return _BOOKS[GroupIndex];
    }
    return _NULL;
  }
};
/**
 * Implementation to
 * ContactBook::__H_ExistsGroup()
 */
ssize_t ContactBook::__H_ExistsGroup(const std::string &GroupName) {
  for (size_t i = 0; i < _BOOKS.size(); i++) {
    if (_BOOKS[i].getGroupName() == GroupName) {
      return (ssize_t)i;
    }
  }
  return (ssize_t)-1;
}
} // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_