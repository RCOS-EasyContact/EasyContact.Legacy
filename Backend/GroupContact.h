/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * GroupContact.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_GROUPCONTACT_H_
#define BACKEND_GROUPCONTACT_H_
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include "Contact.h"
/**
 * <GroupContact> Represents an Mutable Object for a Group of <Contact> Objects
 * <GroupContact> Contains:
 *           <std::string> -------- Name of the Group
 *           <std::vector<Contact>> Group of <Contact> Objects
 */
class GroupContact {
  std::string _NAME;
  std::vector<Contact> _GROUP;
  /**
   * Sort the Group from Large <Contact> Object to Small <Contact> Object
   * Implemented with Merge Sort Algorithm
   * @param <std::vector<Contact>> : Group of <Contact> Objects to be Sort
   * @return <std::vector<Contact>> : Group of <Contact> Objects Sorted
   */
  std::vector<Contact> __H_MergeSort(const std::vector<Contact> &Input);

 public:
  /**
   * Default Class Constructor
   */
  GroupContact() = default;
  /**
   * Default Class Constructor
   * @param <std::string> Name : Name of the Group
   */
  explicit GroupContact(const std::string &Name) { _NAME = Name; }
  /**
   * Class Copy Constructor
   * Redirects to this->operator=()
   * @param <GroupContact> Input : Another Instance of <GroupContact> Class
   */
  explicit GroupContact(const GroupContact &Input) : GroupContact() {
    this->operator=(Input);
  }
  /**
   * Class Move Constructor
   * Redirects to this->operator=()
   * @param <GroupContact> Input : Another Instance of <GroupContact> Class
   */
  explicit GroupContact(const GroupContact &&Input) noexcept : GroupContact() {
    this->operator=(std::move(Input));
  }
  /**
   * Representation Accessor
   * @return <std::string> : Get Name of the Group
   */
  const std::string &getGroupName() { return _NAME; }
  /**
   * Representation Accessor
   * @return <std::vector<Contact>> : Get the Whole Group of Contact Objects
   */
  const std::vector<Contact> &getGroupContact() { return _GROUP; }
  /**
   * Representation Modifier
   * Does Not Allow Duplicate <Contact> Objects
   * @param <Contact> NewContact : Contact Information to be Saved
   * @return <bool> : Add New Contact Successfulness
   */
  inline bool addNewContact(const Contact &NewContact) {
    try {
      if (std::find(_GROUP.begin(), _GROUP.end(), NewContact) == _GROUP.end()) {
        _GROUP.push_back(NewContact);
        return true;
      }
    } catch (std::exception &ERR) {
      std::cerr << "GroupContact: " << ERR.what() << std::endl;
    }
    return false;
  }
  /**
   * Representation Modifier
   * Sets the Name of the Group
   * @param <std::string> Name : New Name for the Group
   * @return <std::string> : New Name of the Group
   */
  const std::string &setGroupName(const std::string &Name) {
    try {
      _NAME = Name;
    } catch (std::exception &ERR) {
      std::cerr << "GroupContact: " << ERR.what() << std::endl;
    }
    return this->getGroupName();
  }
  /**
   * Sort the Group from Large <Contact> Object to Small <Contact> Object
   * @return <bool> : Sort Successfulness
   */
  inline bool sortGroupContact() {
    if (!_GROUP.size()) {
      return false;
    }
    try {
      _GROUP = this->__H_MergeSort(_GROUP);
    } catch (std::exception &ERR) {
      std::cerr << "GroupContact: " << ERR.what() << std::endl;
    }
    return true;
  }
  /**
   * Calculates Hash Code
   * @param <uint64_t (long unsigned int)> : Hash Table Stack Size
   * @return <uint64_t (long unsigned int)> : Hash Code for Current Instance
   */
  uint64_t Hash(const uint64_t &STACK) {
    uint64_t BUFFER = 0;
    for (const char &N : _NAME) {
      BUFFER += static_cast<int>(N);
    }
    return (uint64_t)(BUFFER % STACK);
  }
  /**
   * Compare Different Instances
   * @param <GroupContact> Input : Another Instance of <GroupContact> Class
   * @return <bool> : Compares Between Two Instances
   */
  bool operator==(const GroupContact &Input) {
    return this->_NAME == Input._NAME;
  }
  friend bool operator<(const GroupContact &LEFT, const GroupContact &RIGHT) {
    return LEFT._GROUP.size() < RIGHT._GROUP.size();
  }
  uint64_t operator%(const uint64_t &STACK) { return this->Hash(STACK); }
  friend std::ostream &operator<<(std::ostream &FILE,
                                  const GroupContact &Input) {
    try {
      FILE << "<" << Input._NAME << ":" << Input._GROUP.size() << ">";
      for (const Contact &N : Input._GROUP) {
        FILE << ", <" << N << ">";
      }
    } catch (std::exception &ERR) {
      std::cerr << "GroupContact: " << ERR.what() << std::endl;
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
    try {
      return _GROUP[ContactIndex];
    } catch (std::exception &ERR) {
      std::cerr << "GroupContact: " << ERR.what() << std::endl;
    }
  }
};
/**
 * Implementation to
 * GroupContact::__H_MergeSort()
 */
std::vector<Contact>
GroupContact::__H_MergeSort(const std::vector<Contact> &Input) {
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

  return RESULT_VEC;
}
#endif  // BACKEND_GROUPCONTACT_H_
