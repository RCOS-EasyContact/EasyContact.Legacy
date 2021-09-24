/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * ContactBook.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTBOOK_H_
#define BACKEND_CONTACTBOOK_H_
#include "GroupContact.h"
class ContactBook {
  std::vector<GroupContact> _CBOOK;
  ssize_t __H_ExistsGroup(const std::string &GroupName);

public:
  ContactBook() = default;
  bool addNewGroup(const std::string &GroupName) {
    const ssize_t GroupIndex = __H_ExistsGroup(GroupName);
    if (GroupIndex == -1) {
      _CBOOK.push_back(GroupContact(GroupName));
      return true;
    }
    return false;
  };
  bool addNewContact(const std::string &GroupName, const Contact &NewContact) {
    const ssize_t GroupIndex = __H_ExistsGroup(GroupName);
    if (GroupIndex != -1) {
      return _CBOOK[GroupIndex].addNewContact(NewContact);
    }
    return false;
  }
};
/**
 * Implementation to
 * ContactBook::__H_ExistsGroup()
 */
ssize_t ContactBook::__H_ExistsGroup(const std::string &GroupName) {
  for (size_t i = 0; i < _CBOOK.size(); i++) {
    if (_CBOOK[i].getGroupName() == GroupName) {
      return (ssize_t)i;
    }
  }
  return (ssize_t)-1;
}

#endif // BACKEND_CONTACTBOOK_H_
