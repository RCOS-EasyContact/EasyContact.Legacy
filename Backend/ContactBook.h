/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * ContactBook.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTBOOK_H_
#define BACKEND_CONTACTBOOK_H_
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include "GroupContact.h"
class ContactBook {
  std::vector<GroupContact> _BOOKS;
  inline ssize_t __H_ExistsGroup(const std::string &GroupName);
  static GroupContact _NULL;

 public:
  ContactBook() = default;
  const GroupContact &getGroup(const std::string &GroupName) {
    try {
      return _BOOKS[__H_ExistsGroup(GroupName)];
    } catch (std::exception &ERR) {
      std::cerr << "ContactBook: " << ERR.what() << std::endl;
    }
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
    try {
      for (const GroupContact &N : Input._BOOKS) {
        FILE << N << " | ";
      }
    } catch (std::exception &ERR) {
      std::cerr << "ContactBook: " << ERR.what() << std::endl;
    }
    return FILE;
  }
  inline bool operator+=(const std::string &GroupName) {
    return this->addNewGroup(GroupName);
  }
  GroupContact &operator[](const uint64_t &GroupIndex) {
    try {
      if (GroupIndex < _BOOKS.size()) {
        return _BOOKS[GroupIndex];
      }
    } catch (std::exception &ERR) {
      std::cerr << "ContactBook: " << ERR.what() << std::endl;
    }
    return _NULL;
  }
};
/**
 * Implementation to
 * ContactBook::__H_ExistsGroup()
 */
ssize_t ContactBook::__H_ExistsGroup(const std::string &GroupName) {
  try {
    for (size_t i = 0; i < _BOOKS.size(); i++) {
      if (_BOOKS[i].getGroupName() == GroupName) {
        return (ssize_t)i;
      }
    }
  } catch (std::exception &ERR) {
    std::cerr << "ContactBook: " << ERR.what() << std::endl;
  }
  return (ssize_t)-1;
}
#endif  // BACKEND_CONTACTBOOK_H_
