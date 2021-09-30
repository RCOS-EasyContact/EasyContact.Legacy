/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * GroupContact.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_GROUPCONTACT_CPP_
#define BACKEND_CONTACTSYSTEM_GROUPCONTACT_CPP_
#include "GroupContact.h"
std::vector<BCS::Contact>
BCS::GroupContact::__H_MergeSort(const std::vector<BCS::Contact> &Input) {
  // Recursion Base Case
  if (Input.size() == 1) {
    return Input;
  }
  // Construct Vectors
  const uint64_t LEFT_SIZE = Input.size() / 2;
  const uint64_t RIGHT_SIZE = Input.size() % 2 ? LEFT_SIZE + 1 : LEFT_SIZE;
  std::vector<BCS::Contact> LEFT_VEC;
  std::vector<BCS::Contact> RIGHT_VEC;
  std::vector<BCS::Contact> RESULT_VEC;
  for (uint64_t i = 0; i < LEFT_SIZE; i++) {
    LEFT_VEC.push_back(Input[i]);
  }
  for (uint64_t i = 0; i < RIGHT_SIZE; i++) {
    RIGHT_VEC.push_back(Input[LEFT_SIZE + i]);
  }
  // Recursive Sorting
  LEFT_VEC = __H_MergeSort(LEFT_VEC);
  RIGHT_VEC = __H_MergeSort(RIGHT_VEC);
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
  // Return Sorted Vector
  return RESULT_VEC;
}
bool BCS::GroupContact::addNewContact(const BCS::Contact &NewContact) {
  if (std::find(_GROUP.begin(), _GROUP.end(), NewContact) == _GROUP.end()) {
    _GROUP.push_back(NewContact);
    return true;
  }
  return false;
}
bool BCS::GroupContact::sortGroupContact() {
  if (!_GROUP.size()) {
    return false;
  }
  _GROUP = this->__H_MergeSort(_GROUP);
  return true;
}
uint64_t BCS::GroupContact::Hash(const uint64_t &STACK) {
  uint64_t BUFFER = 0;
  for (const char &N : _NAME) {
    BUFFER += static_cast<int>(N);
  }
  return (uint64_t)(BUFFER % STACK);
}
BCS::GroupContact &
BCS::GroupContact::operator=(const BCS::GroupContact &Input) {
  if (this != &Input) {
    this->_NAME = Input._NAME;
    this->_GROUP = Input._GROUP;
  }
  return *this;
}
BCS::GroupContact &
BCS::GroupContact::operator=(const BCS::GroupContact &&Input) noexcept {
  if (this != &Input) {
    this->_NAME = Input._NAME;
    this->_GROUP = Input._GROUP;
  }
  return *this;
}
BCS::Contact &BCS::GroupContact::operator[](const uint64_t &ContactIndex) {
  try {
    if (ContactIndex >= _GROUP.size()) {
      throw ContactIndex;
    }
  } catch (uint64_t Exception) {
    std::cerr << "Caught Runtime Exception" << std::endl;
    std::cerr << "GroupContact: "
              << "Request Index: " << Exception << " OUT-OF-BOUNDS"
              << std::endl;
  }
  return _GROUP[ContactIndex];
}
#endif  // BACKEND_CONTACTSYSTEM_GROUPCONTACT_CPP_
