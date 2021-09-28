/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * ContactBook.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_
#define BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include "GroupContact.h"
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
class ContactBook {
  std::vector<GroupContact> _BOOKS;
  ssize_t __H_ExistsGroup(const std::string &GroupName);

 public:
  ContactBook() = default;
  const GroupContact &getGroup(const std::string &GroupName) {
    return _BOOKS[__H_ExistsGroup(GroupName)];
  }
  bool addNewGroup(const std::string &GroupName);
  bool addNewContact(const std::string &GroupName, const Contact &NewContact);
  friend std::ostream &operator<<(std::ostream &FILE,
                                  const ContactBook &Input) {
    for (const GroupContact &N : Input._BOOKS) {
      FILE << N << " | ";
    }
    return FILE;
  }
  bool operator+=(const std::string &GroupName) {
    return this->addNewGroup(GroupName);
  }
  GroupContact &operator[](const uint64_t &GroupIndex);
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_
