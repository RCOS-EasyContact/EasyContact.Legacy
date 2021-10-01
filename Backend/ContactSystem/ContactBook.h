/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * ContactBook.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_
#define BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_
// C++ Standard Library
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
// Standard Template Library
#include <deque>
#include <map>
#include <vector>
// ContactSystem Header Files
#include "Contact.h"
#include "Triple.h"
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
class ContactBook {
  std::map<uint8_t, std::string> _TAG_MAPPING;
  std::deque<Contact> _BOOK_SYSTEM;

public:
  ContactBook() = default;
  bool addContact(const Contact &NewContact);
  bool removeContact(const std::string &ExistContact);
  bool addTag(const std::string &TagName);
  bool removeTag(const std::string &TagName);
  bool assignTag(const std::string &TagName, const std::string &ExistContact);
  [[nodiscard]] std::vector<
      BCS::Triple<std::string, std::string, std::vector<std::string>>>
  getAllContacts();
  friend std::ostream &operator<<(std::ostream &FILE,
                                  const ContactBook &Input) {
    for (size_t i = 0; i < Input._BOOK_SYSTEM.size(); i++) {
      FILE << "<" << i << ">: ";
    }
    return FILE;
  }
};
} // namespace BCS
#endif // BACKEND_CONTACTSYSTEM_CONTACTBOOK_H_