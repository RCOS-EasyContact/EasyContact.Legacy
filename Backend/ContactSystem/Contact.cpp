#ifndef BACKEND_CONTACTSYSTEM_CONTACT_CPP_
#define BACKEND_CONTACTSYSTEM_CONTACT_CPP_
#include "Contact.h"
  uint64_t BCS::Contact::Hash(const uint64_t &STACK) {
    uint64_t BUFFER = 0;
    for (const char &N : _ADDRESS) {
      BUFFER += static_cast<int>(N);
    }
    return (uint64_t)(BUFFER % STACK);
  }
  BCS::Contact &BCS::Contact::operator=(const BCS::Contact &Input) {
    if (this != &Input) {
      this->_NAME = Input._NAME;
      this->_ADDRESS = Input._ADDRESS;
      this->_PHONE = Input._PHONE;
      this->_LATEST = Input._LATEST;
      this->_RECEIVED = Input._RECEIVED;
    }
    return *this;
  }
    BCS::Contact &BCS::Contact::operator=(const BCS::Contact &&Input) noexcept {
    if (this != &Input) {
      this->_NAME = Input._NAME;
      this->_ADDRESS = Input._ADDRESS;
      this->_PHONE = Input._PHONE;
      this->_LATEST = Input._LATEST;
      this->_RECEIVED = Input._RECEIVED;
    }
    return *this;
  }
    BCS::Contact &BCS::Contact::operator+=(const std::string &LatestEmail) {
    if (!LatestEmail.empty()) {
      this->_LATEST = LatestEmail;
      this->_RECEIVED++;
    }
    return *this;
  }
  #ifdef DEPLETED
    BCS::Contact &BCS::Contact::operator[](const uint64_t &NumReceived) {
    this->_RECEIVED = NumReceived;
    return *this;
  }
  #endif
  #endif