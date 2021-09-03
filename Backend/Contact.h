#ifndef RCOS_EASYCONTACT_CXX_HEADER_CONTACT
#define RCOS_EASYCONTACT_CXX_HEADER_CONTACT
#include <iostream>
#include <string>
/**
 * <Contact> Represents an Mutable Object for Contact Information
 * <Contact> Contains:
 *           <std::string> Phone Number
 *           <std::string> Contact Name
 *           <std::string> Email Address
 *           <std::string> Latest Email
 *           <long unsigned int> Number Emails Received
 */
class Contact {
  std::string _PHONE;
  std::string _NAME;
  std::string _ADDRESS;
  std::string _LATEST;
  long unsigned int _RECEIVED;

public:
  /**
   * Default Class Constructor
   * @param <std::string> Phone : Phone Number to be Stored
   * @param <std::string> Name : Contact Name to be Stored
   * @param <std::string> Address : Email Address to be Stored
   * @param <std::string> LatestEmail : Latest Email Received from this Email
   * Address
   * @param <long unsigned int> NumReceived : Total Number of Emails Received
   * from this Email Address
   */
  explicit Contact(const std::string &Phone, const std::string &Name,
                   const std::string &Address, const std::string &LatestEmail,
                   const long unsigned int &NumReceived) {
    _PHONE = Phone;
    _NAME = Name;
    _ADDRESS = Address;
    _LATEST = LatestEmail;
    _RECEIVED = NumReceived;
  }
  /**
   * Class Copy Constructor
   * @param <Contact> Input : Another Instance of <Contact> Class
   */
  explicit Contact(const Contact &Input) {
    this->_PHONE = Input._PHONE;
    this->_NAME = Input._NAME;
    this->_ADDRESS = Input._ADDRESS;
    this->_LATEST = Input._LATEST;
    this->_RECEIVED = Input._RECEIVED;
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
   * @return <long unsigned int> : Get Total Number of Emails Received
   */
  const long unsigned int &getReceived() { return _RECEIVED; }
  /**
   * Class Function
   * @param <long unsigned int> : Hash Table Stack Size
   * @return <long unsigned int> : Hash Code for Current Instance
   */
  long unsigned int Hash(const long unsigned int &STACK) {
    long unsigned int BUFFER = 0;
    for (const char &N : _NAME) {
      BUFFER += (int)N;
    }
    for (const char &N : _ADDRESS) {
      BUFFER += (int)N;
    }
    return (long unsigned int)(BUFFER % STACK);
  }
  /**
   * Operator Overload
   * @param <Contact> Input : Another Instance of <Contact> Class
   * @return <bool> : Compares Between Two Instances
   */
  bool operator==(const Contact &Input) { return this->_NAME == Input._NAME; }
  /**
   * Operator Overload
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
   * Operator Overload
   * @param <Contact> Input : Another Instance of <Contact> Class
   * @return <Contact> : Reference to Current Instance
   */
  Contact &operator=(const Contact &Input) {
    if (!this->operator==(Input)) {
      this->_PHONE = Input._PHONE;
      this->_NAME = Input._NAME;
      this->_ADDRESS = Input._ADDRESS;
      this->_LATEST = Input._LATEST;
      this->_RECEIVED = Input._RECEIVED;
    }
    return *this;
  }
  /**
   * Operator Overload
   * @param <std::string> LatestEmail : Latest Email Received from this Email
   * Address
   * @return <Contact> : Reference to Current Instance
   */
  Contact &operator+=(const std::string &LatestEmail) {
    if (!LatestEmail.empty()) {
      this->_LATEST = LatestEmail;
      this->_RECEIVED++;
    }
    return *this;
  }
  /**
   * Operator Overload
   * @param <long unsigned int> NumReceived : Total Number of Emails Received
   * from this Email Address
   * @return <Contact> : Reference to Current Instance
   */
  Contact &operator[](const long unsigned int &NumReceived) {
    this->_RECEIVED = NumReceived;
    return *this;
  }
};
#endif
