/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Tags.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_TAGS_H_
#define BACKEND_CONTACTSYSTEM_TAGS_H_
// C++ Standard Library
#include <string>
#include <utility>
// Standard Template Library
#include <map>
#include <set>
#include <vector>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
/**
 * Mutable Class
 * <Tags> Repersents
 * Tag Database That Manages All
 * The Tags Associated With Contacts
 * -----   -----   -----
 * No Duplicate Tag Names Are Allowed
 */
class Tags {
  std::map<std::string, std::set<std::string>> _TAGS;

 public:
  /**
   * Default Class Constructor
   */
  Tags() = default;
  /**
   * Create A New Tag
   * Duplicate Tags Are Not Allowed
   * @param <std::string> : Tag Name
   * @return <bool> : Success or Failed (Existing Tag)
   */
  bool newTag(const std::string &TagName);
  /**
   * Remove A Existing Tag
   * All Contacts Associated With This Tag Will Also Be Removed From This Tag
   * Group. The Contact Itself Will Not Be Removed, However
   * @param <std::string> : Tag to be Removed
   * @return <bool> : Success or Failed (Tag not Exist)
   */
  bool removeTag(const std::string &TagName);
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
   * Get All Tag Names
   * @return <std::vector<std::string>> : All Tag Names
   */
  std::vector<std::string> getAllTags();
  /**
   * Get All Contacts Tagged with the Tag Name
   * @param <std::string> : Tag Name
   * @return <std::vector<std::string>> : All Contacts With This Tag
   */
  std::vector<std::string> getTagContains(const std::string &TagName);
  /**
   * Get All Tags Associated with one Contact
   * @param <std::string> : Contact Name
   * @return <std::vector<std::string>> : All Tags Associated
   */
  std::vector<std::string> getNameInTags(const std::string &ContactName);
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_TAGS_H_
