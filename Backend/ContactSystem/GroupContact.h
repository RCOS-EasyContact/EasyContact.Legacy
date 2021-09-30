/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * GroupContact.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_GROUPCONTACT_H_
#define BACKEND_CONTACTSYSTEM_GROUPCONTACT_H_
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include "Contact.h"
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
/**
 * <GroupContact> Represents an Mutable Object for a Group of <Contact> Objects
 * <GroupContact> Contains:
 *           <std::string> : Name of the Group
 *           <std::vector<Contact>> : Group of <Contact> Objects
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
  [[nodiscard]] std::vector<Contact>
  __H_MergeSort(const std::vector<Contact> &Input);

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
  [[nodiscard]] const std::string &getGroupName() { return _NAME; }
  /**
   * Representation Accessor
   * @return <std::vector<Contact>> : Get the Whole Group of Contact Objects
   */
  [[nodiscard]] const std::vector<Contact> &getGroupContact() { return _GROUP; }
  /**
   * Representation Modifier
   * Does Not Allow Duplicate <Contact> Objects
   * @param <Contact> NewContact : Contact Information to be Saved
   * @return <bool> : Add New Contact Successfulness
   */
  bool addNewContact(const Contact &NewContact);
  /**
   * Sort the Group from Large <Contact> Object to Small <Contact> Object
   * @return <bool> : Sort Successfulness
   */
  bool sortGroupContact();
  /**
   * Calculates Hash Code
   * @param <uint64_t> : Hash Table Stack Size
   * @return <uint64_t> : Hash Code for Current Instance
   */
  [[nodiscard]] uint64_t Hash(const uint64_t &STACK);
  /**
   * Compare Different Instances
   * @param <GroupContact> Input : Another Instance of <GroupContact> Class
   * @return <bool> : Compares Between Two Instances
   */
  bool operator==(const GroupContact &Input) {
    return this->_NAME == Input._NAME;
  }
  bool operator<(const GroupContact &Input) {
    return this->_GROUP.size() < Input._GROUP.size();
  }
  [[nodiscard]] uint64_t operator%(const uint64_t &STACK) {
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
  GroupContact &operator=(const GroupContact &Input);
  GroupContact &operator=(const GroupContact &&Input) noexcept;
  bool operator+=(const Contact &NewContact) {
    return this->addNewContact(NewContact);
  }
  [[nodiscard]] Contact &operator[](const uint64_t &ContactIndex);
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_GROUPCONTACT_H_
