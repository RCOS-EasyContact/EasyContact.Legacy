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
  explicit GroupContact(const GroupContact &Input) : GroupContact() {
    this->operator=(Input);
  }
  explicit GroupContact(const GroupContact &&Input) noexcept : GroupContact() {
    this->operator=(std::move(Input));
  }
  const std::string &getGroupName() { return _NAME; }
  const std::string &setGroupName(const std::string &Name) {
    _NAME = Name;
    return _NAME;
  }
  long unsigned int Hash(const long unsigned int &STACK) {
    long unsigned int BUFFER = 0;
    for (const char &N : _NAME) {
      BUFFER += (int)N;
    }
    return (long unsigned int)(BUFFER % STACK);
  }
  bool operator==(const GroupContact &Input) {
    return this->_NAME == Input._NAME;
  }
  friend bool operator<(const GroupContact &LEFT, const GroupContact &RIGHT) {
    return LEFT._GROUP.size() < RIGHT._GROUP.size();
  }
  long unsigned int operator%(const long unsigned int &STACK) {
    return this->Hash(STACK);
  }
  friend std::ostream &operator<<(std::ostream &FILE,
                                  const GroupContact &Input) {
    FILE << "<" << Input._NAME << ":" << Input._GROUP.size() << ">";
    for (const Contact &N : Input._GROUP) {
      FILE << ", <" << N << ">";
    }
    return FILE;
  }
  GroupContact &operator=(const GroupContact &Input) {
    if (this != &Input) {
      this->_NAME = Input._NAME;
      this->_GROUP = Input._GROUP;
    }
    return *this;
  }
  GroupContact &operator=(const GroupContact &&Input) noexcept {
    if (this != &Input) {
      this->_NAME = Input._NAME;
      this->_GROUP = Input._GROUP;
    }
    return *this;
  }
  inline bool operator+=(const Contact &NewContact) {
    if (std::find(_GROUP.begin(), _GROUP.end(), NewContact) == _GROUP.end()) {
      _GROUP.push_back(NewContact);
      return true;
    }
    return false;
  }
  Contact &operator[](const long unsigned int &ContactIndex) {
    return _GROUP[ContactIndex];
  }
};
#endif
