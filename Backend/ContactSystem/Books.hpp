/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Books.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_BOOKS_HPP_
#define BACKEND_CONTACTSYSTEM_BOOKS_HPP_
// C++ Standard Library
#include <algorithm>
#include <string>
#include <utility>
// Standard Template Library
#include <unordered_map>
#include <unordered_set>
// Backend/ContactSystem
#include "Key.hpp"
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
/**
 * Mutable Class
 * <Books> Repersents
 * Contact Database That Manages All
 * Contacts & Tags
 */
class Books {
  std::unordered_set<BCS::Key> _DB;
  std::unordered_map<std::string, std::unordered_set<std::string>> _TAGS;

 public:
  /**
   * Default Class Constructor
   */
  Books() = default;
  /**
   * Add New Contact
   * Duplicate Contacts Are Not Allowed
   * @param <BCS::Key> : Contact Name
   * @return <bool> : Success or Failed (Existing Contact)
   */
  bool newContact(const BCS::Key &NewContact);
  /**
   * Create A New Tag
   * Duplicate Tags Are Not Allowed
   * @param <std::string> : Tag Name
   * @return <bool> : Success or Failed (Existing Tag)
   */
  bool newTag(const std::string &TagName);
  /**
   * Remove A Existing Contact
   * Will Also Remove From Any Existing
   * Tag Group
   * @param <std::string> : Contact to be Removed
   * @return <bool> : Success or Failed (Tag not Exist)
   */
  bool removeContact(const std::string &ExistContact);
  /**
   * Remove A Existing Tag
   * All Contacts Associated With This Tag Will Also Be Removed From This Tag
   * Group. The Contact Itself Will Not Be Removed, However
   * @param <std::string> : Tag to be Removed
   * @return <bool> : Success or Failed (Tag not Exist)
   */
  bool removeTag(const std::string &TagName);
  /**
   * Get All the Contacts
   * @return <std::unordered_set<BCS::Key>> : All Contacts
   */
  const std::unordered_set<BCS::Key> &getAllContacts();
  /**
   * Get All Tag Names
   * @return <std::unordered_set<std::string>> : All Tag Names
   */
  std::unordered_set<std::string> getAllTags();
  /**
   * Assign A Existing Tag to One Contact
   * @param <std::string> : Tag Name
   * @param <std::string> : Contact Name
   */
  void assignTagTo(const std::string &TagName, const std::string &ContactName);
  /**
   * Remove An Assigned Tag From One Contact
   * @param <std::string> : Tag Name
   * @param <std::string> : Contact Name
   */
  void removeTagFor(const std::string &TagName, const std::string &ContactName);
  /**
   * Remove All Tags Associated With One Contact
   * @param <std::string> : Contact Name
   */
  void clearTagFor(const std::string &ContactName);
  /**
   * Get All Contacts Tagged with the Tag Name
   * @param <std::string> : Tag Name
   * @return <std::unordered_set<std::string>> : All Contacts With This Tag
   */
  std::unordered_set<std::string> getTagContains(const std::string &TagName);
  /**
   * Get All Tags Associated with one Contact
   * @param <std::string> : Contact Name
   * @return <std::unordered_set<std::string>> : All Tags Associated
   */
  std::unordered_set<std::string> getNameInTags(const std::string &ContactName);
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_BOOKS_HPP_
