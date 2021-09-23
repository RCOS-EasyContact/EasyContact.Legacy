/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * GroupContact.h
 * Copyright [2021] <RCOS-EasyContact>
 */

#ifndef BACKEND_GROUPCONTACT_H_
#define BACKEND_GROUPCONTACT_H_
#include "Contact.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
class GroupContact {
  std::string _NAME;
  std::vector<Contact> _GROUP;
  std::vector<Contact> MergeSort(const std::vector<Contact> &Input);

public:
  /**
   * Default Class Constructor
   */
  GroupContact() = default;
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
    if (!_GROUP.size())
      return false;
    _GROUP = this->MergeSort(_GROUP);
    return true;
  }
  uint64_t Hash(const uint64_t &STACK) {
    uint64_t BUFFER = 0;
    for (const char &N : _NAME) {
      BUFFER += (int)N;
    }
    return (uint64_t)(BUFFER % STACK);
  }
  bool operator==(const GroupContact &Input) {
    return this->_NAME == Input._NAME;
  }
  friend bool operator<(const GroupContact &LEFT, const GroupContact &RIGHT) {
    return LEFT._GROUP.size() < RIGHT._GROUP.size();
  }
  uint64_t operator%(const uint64_t &STACK) { return this->Hash(STACK); }
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
  Contact &operator[](const uint64_t &ContactIndex) {
    return _GROUP[ContactIndex];
  }
};
/**
 * Implementation to
 * GroupContact::MergeSort()
 */
std::vector<Contact>
GroupContact::MergeSort(const std::vector<Contact> &Input) {
  // Recursion Base Case
  if (Input.size() == 1)
    return Input;

  // Construct Vectors
  const uint64_t LEFT_SIZE = Input.size() / 2;
  const uint64_t RIGHT_SIZE = Input.size() % 2 ? LEFT_SIZE + 1 : LEFT_SIZE;
  std::vector<Contact> LEFT_VEC;
  std::vector<Contact> RIGHT_VEC;
  std::vector<Contact> RESULT_VEC;
  for (uint64_t i = 0; i < LEFT_SIZE; i++)
    LEFT_VEC.push_back(Input[i]);
  for (uint64_t i = 0; i < RIGHT_SIZE; i++)
    RIGHT_VEC.push_back(Input[LEFT_SIZE + i]);

  // Recursive Sorting
  LEFT_VEC = MergeSort(LEFT_VEC);
  RIGHT_VEC = MergeSort(RIGHT_VEC);

  // Merge from Large to Small
  uint64_t L = 0;
  uint64_t R = 0;
  while (L < LEFT_SIZE && R < RIGHT_SIZE) {
    if (LEFT_VEC[L] < RIGHT_VEC[R]) {
      RESULT_VEC.push_back(RIGHT_VEC[R]);
      R++;
    } else {
      RESULT_VEC.push_back(LEFT_VEC[L]);
      L++;
    }
  }
  while (L < LEFT_SIZE) {
    RESULT_VEC.push_back(LEFT_VEC[L]);
    L++;
  }
  while (R < RIGHT_SIZE) {
    RESULT_VEC.push_back(RIGHT_VEC[R]);
    R++;
  }

  return RESULT_VEC;
}

#endif // BACKEND_GROUPCONTACT_H_
