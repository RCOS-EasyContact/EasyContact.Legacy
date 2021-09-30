/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Contact.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_CONTACT_H_
#define BACKEND_CONTACTSYSTEM_CONTACT_H_
#include <iostream>
#include <string>
#include <utility>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
/**
 * <Contact> Represents an Mutable Object for Contact Information
 * <Contact> Contains:
 *           <std::string> : Contact Name
 *           <std::string> : Email Address
 *           <std::string> : Phone Number
 *           <std::string> : Latest Email
 *           <uint64_t> : Number Emails Received
 */
class Contact {
  std::string _NAME;
  std::string _ADDRESS;
  std::string _PHONE;
  std::string _LATEST;
  uint64_t _RECEIVED;

 public:
  /**
   * Default Class Constructor
   */
  Contact() = default;
  /**
   * Default Class Constructor
   * @param <std::string> Name : Contact Name to be Stored
   * @param <std::string> Address : Email Address to be Stored
   * @param <std::string> Phone : Phone Number to be Stored
   * @param <std::string> LatestEmail : Latest Email Received from this Email
   * Address
   * @param <uint64_t> NumReceived : Total Number of Emails
   * Received from this Email Address
   */
  explicit Contact(const std::string &Name, const std::string &Address,
                   const std::string &Phone, const std::string &LatestEmail,
                   const uint64_t &NumReceived) {
    _NAME = Name;
    _ADDRESS = Address;
    _PHONE = Phone;
    _LATEST = LatestEmail;
    _RECEIVED = NumReceived;
  }
  /**
   * Class Copy Constructor
   * Redirects to this->operator=()
   * @param <Contact> Input : Another Instance of <Contact> Class
   */
  explicit Contact(const Contact &Input) : Contact() { this->operator=(Input); }
  /**
   * Class Move Constructor
   * Redirects to this->operator=()
   * @param <Contact> Input : Another Instance of <Contact> Class
   */
  explicit Contact(const Contact &&Input) noexcept : Contact() {
    this->operator=(std::move(Input));
  }
  /**
   * Representation Accessor
   * @return <std::string> : Get Saved Phone Number
   */
  const std::string &getPhone() { return _PHONE; }
  /**
   * Representation Accessor
   * @return <std::string> : Get Saved Contact Name
   */
  const std::string &getName() { return _NAME; }
  /**
   * Representation Accessor
   * @return <std::string> : Get Saved Email Address
   */
  const std::string &getAddress() { return _ADDRESS; }
  /**
   * Representation Accessor
   * @return <std::string> : Get Latest Email Received
   */
  const std::string &getEmail() { return _LATEST; }
  /**
   * Representation Accessor
   * @return <uint64_t> : Get Total Number of Emails
   * Received
   */
  const uint64_t &getReceived() { return _RECEIVED; }
  /**
   * Calculates Hash Code
   * @param <uint64_t> : Hash Table Stack Size
   * @return <uint64_t> : Hash Code for Current Instance
   */
  [[nodiscard]] constexpr uint64_t Hash(const uint64_t &STACK);
  /**
   * Compare Different Instances
   * @param <Contact> Input : Another Instance of <Contact> Class
   * @return <bool> : Compares Between Two Instances
   */
  bool operator==(const Contact &Input) { return this->_NAME == Input._NAME; }
  /**
   * Compare Different Instances
   * @param <Contact> LEFT : An Instance of <Contact> Class
   * @param <Contact> RIGHT : An Instance of <Contact> Class
   * @return <bool> : Compares Between Two Instances
   */
  friend bool operator<(const Contact &LEFT, const Contact &RIGHT) {
    return LEFT._RECEIVED < RIGHT._RECEIVED;
  }
  /**
   * Calculates Hash Code
   * Redirects to this->Hash()
   * @param <uint64_t> : Hash Table Stack Size
   * @return <uint64_t> : Hash Code for Current Instance
   */
  [[nodiscard]] constexpr uint64_t operator%(const uint64_t &STACK) { return this->Hash(STACK); }
  /**
   * Print Class Representation to File Descriptor
   * @param <std::ostream> FILE : File Descriptor
   * @param <Contact> Input : Another Instance of <Contact> Class
   * @return <std::ostream> : Original File Descriptor
   */
  friend std::ostream &operator<<(std::ostream &FILE, const Contact &Input) {
    FILE << "\"" << Input._NAME << "\",\"" << Input._ADDRESS << "\",\""
         << Input._PHONE << "\",\"" << Input._LATEST << "\",\""
         << Input._RECEIVED << "\"";
    return FILE;
  }
  /**
   * Class Copy Constructor
   * @param <Contact> Input : Another Instance of <Contact> Class
   * @return <Contact> : Reference to Current Instance
   */
  Contact &operator=(const Contact &Input);
  /**
   * Class Move Constructor
   * @param <Contact> Input : Another Instance of <Contact> Class
   * @return <Contact> : Reference to Current Instance
   */
  Contact &operator=(const Contact &&Input) noexcept;
  /**
   * Received New Email from this Email Address
   * @param <std::string> LatestEmail : Latest Email Received from this Email
   * Address
   * @return <Contact> : Reference to Current Instance
   */
  Contact &operator+=(const std::string &LatestEmail);
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_CONTACT_H_
