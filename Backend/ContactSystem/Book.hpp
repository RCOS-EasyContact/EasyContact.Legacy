/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Book.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_BOOK_HPP_
#define BACKEND_CONTACTSYSTEM_BOOK_HPP_
// C++ Standard Library
#include <algorithm>
#include <string>
#include <utility>
// Standard Template Library
#include <set>
#include <vector>
// Backend/ContactSystem
#include "Key.hpp"
#include "Tags.hpp"
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
/**
 * Mutable Class
 * <Book> Repersents
 * Contact Database That Manages All
 * Contacts & Tags
 */
class Book {
  std::set<BCS::Key> _BOOK;
  BCS::Tags _TAGS;

 public:
  /**
   * Default Class Constructor
   */
  Book() = default;
  /**
   * Add New Contact
   * Duplicate Contacts Are Not Allowed
   * @param <BCS::Key> : Contact Name
   * @return <bool> : Success or Failed (Existing Contact)
   */
  bool addContact(const Key &NewContact);
  /**
   * Remove A Existing Contact
   * Will Also Remove From Existing
   * Tag Group
   * @param <std::string> : Contact to be Removed
   */
  void removeContact(const std::string &ExistContact);
  /**
   * Get All the Contacts
   * @return std::vector<BCS::Key> : All Contacts
   */
  std::vector<Key> getAllContacts();
  /**
   * Access BCS::Tags Database
   * @return <BCS::Tags> : Tags Reference
   */
  Tags &operator->() { return _TAGS; }
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_BOOK_HPP_
