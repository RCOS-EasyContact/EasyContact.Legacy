/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Book.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_BOOK_H_
#define BACKEND_CONTACTSYSTEM_BOOK_H_
// C++ Standard Library
#include <algorithm>
#include <string>
#include <utility>
// Standard Template Library
#include <set>
#include <vector>
// Backend/ContactSystem
#include "Key.h"
#include "Tags.h"
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
class Book {
  std::set<BCS::Key> _BOOK;
  BCS::Tags _TAGS;

 public:
  /**
   * Default Class Constructor
   */
  Book() = default;
  bool addContact(const Key &NewContact);
  bool removeContact(const std::string &ExistContact);
  std::vector<std::string> getAllContacts();
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_BOOK_H_
