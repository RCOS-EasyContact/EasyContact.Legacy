#ifndef RCOS_EASYCONTACT_CXX_HEADER_GROUPCONTACT
#define RCOS_EASYCONTACT_CXX_HEADER_GROUPCONTACT
#include "Contact.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
class GroupContact {
  std::string _NAME;
  std::vector<Contact> _GROUP;

public:
  explicit GroupContact() = default;
  explicit GroupContact(const std::string &Name) { _NAME = Name; }
  const std::string &getGroupName() { return _NAME; }
  const std::string &setGroupName(const std::string &Name) {
    _NAME = Name;
    return _NAME;
  }
  friend std::ostream &operator<<(std::ostream &FILE,
                                  const GroupContact &Input) {
    FILE << "<" << Input._NAME << ":" << Input._GROUP.size() << ">";
    for (const Contact &N : Input._GROUP) {
      FILE << ", <" << N << ">";
    }
    return FILE;
  }
  inline bool operator+=(const Contact &NewContact) {
    if (std::find(_GROUP.begin(), _GROUP.end(), NewContact) != _GROUP.end()) {
      return false;
    } else {
      _GROUP.push_back(NewContact);
      return true;
    }
    return false;
  }
  const Contact &operator[](const long unsigned int &ContactIndex) {
    return _GROUP[ContactIndex];
  }
};
#endif
