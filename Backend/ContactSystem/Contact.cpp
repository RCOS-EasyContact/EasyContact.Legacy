/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Contact.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_CONTACT_CPP_
#define BACKEND_CONTACTSYSTEM_CONTACT_CPP_
// ContactSystem Header Files
#include "Contact.h"
BCS::Contact &BCS::Contact::operator=(const BCS::Contact &Input) {
  if (this != &Input) {
    this->_NAME = Input._NAME;
    this->_ADDRESS = Input._ADDRESS;
    this->_TAG = Input._TAG;
  }
  return *this;
}
BCS::Contact &BCS::Contact::operator=(const BCS::Contact &&Input) noexcept {
  if (this != &Input) {
    this->_NAME = Input._NAME;
    this->_ADDRESS = Input._ADDRESS;
    this->_TAG = Input._TAG;
  }
  return *this;
}
bool BCS::Contact::operator+=(const uint8_t &NewTag) {
  return _TAG.insert(NewTag).second;
}
bool BCS::Contact::operator-=(const uint8_t &ExistTag) {
  if (_TAG.erase(ExistTag) > 0) {
    return true;
  }
  return false;
}
#endif // BACKEND_CONTACTSYSTEM_CONTACT_CPP_
