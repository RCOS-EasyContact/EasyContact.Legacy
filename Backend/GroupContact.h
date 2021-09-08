#ifndef RCOS_EASYCONTACT_CXX_HEADER_GROUPCONTACT
#define RCOS_EASYCONTACT_CXX_HEADER_GROUPCONTACT
#include "Contact.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
class GroupContact {
  std::string _NAME;
  std::vector<Contact> _GROUP;
  std::vector<Contact> MergeSort(const std::vector<Contact> &Input) {
    std::cout << "Sort<<" << Input.size() << std::endl;
    if (Input.size() == 1)
      return Input;
    const long unsigned int LEFT_SIZE = Input.size() / 2;
    const long unsigned int RIGHT_SIZE =
        Input.size() % 2 ? LEFT_SIZE + 1 : LEFT_SIZE;
    std::vector<Contact> LEFT_VEC;
    std::vector<Contact> RIGHT_VEC;
    for (long unsigned int i = 0; i < LEFT_SIZE; i++)
      LEFT_VEC.push_back(Input[i]);
    for (long unsigned int i = 0; i < RIGHT_SIZE; i++)
      RIGHT_VEC.push_back(Input[LEFT_SIZE + i]);
    if (LEFT_SIZE > 1)
      LEFT_VEC = MergeSort(LEFT_VEC);
    if (RIGHT_SIZE > 1)
      RIGHT_VEC = MergeSort(RIGHT_VEC);
    for (const Contact &N : RIGHT_VEC) {
      for (long unsigned int i = LEFT_VEC.size() / 2;; i++) {
        if (LEFT_VEC[i - 1] < N &&
            (i + 1 != LEFT_VEC.size() ? N < LEFT_VEC[i + 1] : true)) {
          std::vector<Contact>::iterator itr = LEFT_VEC.begin();
          std::advance(itr, i);
          LEFT_VEC.insert(itr, N);
          break;
        }
        if (LEFT_VEC[i + 1] < N) {
          i += i / 2;
          continue;
        }
        if (N < LEFT_VEC[i - 1]) {
          i -= i / 2;
          continue;
        }
      }
    }
    return LEFT_VEC;
  }

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
  const std::vector<Contact> &getGroupContact() { return _GROUP; }
  inline bool addNewContact(const Contact &NewContact) {
    if (std::find(_GROUP.begin(), _GROUP.end(), NewContact) == _GROUP.end()) {
      _GROUP.push_back(NewContact);
      return true;
    }
    return false;
  }
  const std::string &setGroupName(const std::string &Name) {
    _NAME = Name;
    return _NAME;
  }
  inline bool sortGroupContact() {
    _GROUP = this->MergeSort(_GROUP);
    return true;
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
    return this->addNewContact(NewContact);
  }
  Contact &operator[](const long unsigned int &ContactIndex) {
    return _GROUP[ContactIndex];
  }
};
#endif
