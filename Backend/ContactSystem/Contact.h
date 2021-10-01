/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Contact.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_CONTACT_H_
#define BACKEND_CONTACTSYSTEM_CONTACT_H_
// C++ Standard Library
#include <iostream>
#include <string>
#include <utility>
// Standard Template Library
#include <set>
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
 *           <std::set<uint8_t>> : Tags Associated
 */
class Contact {
  std::string _NAME;
  std::string _ADDRESS;
  std::set<uint8_t> _TAG;

public:
  /**
   * Default Class Constructor
   */
  Contact() = default;
  /**
   * Default Class Constructor
   * @param <std::string> Name : Contact Name to be Stored
   * @param <std::string> Address : Email Address to be Stored
   * @param <std::set<uint8_t>> Tags : Associated Tags to be Stored
   */
  explicit Contact(const std::string &Name, const std::string &Address,
                   const std::set<uint8_t> &Tags)
      : _NAME(Name), _ADDRESS(Address), _TAG(Tags) {}
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
   * @return <std::string> : Get Saved Contact Name
   */
  [[nodiscard]] const std::string &getName() { return _NAME; }
  /**
   * Representation Accessor
   * @return <std::string> : Get Saved Email Address
   */
  [[nodiscard]] const std::string &getAddress() { return _ADDRESS; }
  [[nodiscard]] const std::set<uint8_t> &getTags() { return _TAG; }
  /**
   * Compare Different Instances
   * @param <Contact> Input : Another Instance of <Contact> Class
   * @return <bool> : Compares Between Two Instances
   */
  [[nodiscard]] bool operator==(const Contact &Input) {
    return this->_NAME == Input._NAME;
  }
  [[nodiscard]] bool operator==(const std::string &Input) {
    return this->_NAME == Input;
  }
  /**
   * Print Class Representation to File Descriptor
   * @param <std::ostream> FILE : File Descriptor
   * @param <Contact> Input : Another Instance of <Contact> Class
   * @return <std::ostream> : Original File Descriptor
   */
  friend std::ostream &operator<<(std::ostream &FILE, const Contact &Input) {
    FILE << "\"" << Input._NAME << "\",\"" << Input._ADDRESS << "\"";
    for (const uint8_t &N : Input._TAG) {
      FILE << ":" << (int)N;
    }
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
  bool operator+=(const uint8_t &NewTag);
  bool operator-=(const uint8_t &ExistTag);
};
} // namespace BCS
#endif //  BACKEND_CONTACTSYSTEM_CONTACT_H_
