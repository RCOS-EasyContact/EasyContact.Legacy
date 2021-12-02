/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * Contacts.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
// SQL Lite Library
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/VariadicBind.h>
// C++ Standard Library
#include <string>
// Standard Template Library
#include <vector>
// EasyContact Header Files
#include <EasyContact/SysLogs.hpp>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
void CreateDirectory(const std::string &DirName) noexcept;
class Contacts {
 private:
  const std::string RCSID;

 public:
  /**
   * Default Class Constructor
   * @param newRCSID : RCSID For The New Database
   */
  explicit Contacts(const std::string &newRCSID) ;
  /**
   * Create A New Contact Information Inside Database
   * @param Name : Name Of The Contact
   * @param Email : Email Address Of The Contact
   * @return bool : Operation Successfulness
   */
  bool newContact(const std::string &Name, const std::string &Email) noexcept;
  /**
   * Create A New Group Tag
   * @param TagName : Name Of The Group Tag
   * @return bool : Operation Successfulness
   */
  bool newTag(const std::string &TagName) noexcept;
  /**
   * Remove A Existing Contact From Database
   * Will Also Remove This Contact From Any Existing Tag Groups
   * @param Name : Name Of The Contact To Be Removed
   * @return bool : Operation Successfulness
   */
  bool removeContact(const std::string &Name) noexcept;
  /**
   *
   */
  bool removeTag(const std::string &TagName) noexcept;
  [[nodiscard]] std::string getEmailAddress(
      const std::string &Name) const noexcept;
  [[nodiscard]] std::vector<std::string> getAllNames() const noexcept;
  [[nodiscard]] std::vector<std::string> getAllTags() const noexcept;
  [[nodiscard]] std::vector<std::string> getTagContains(
      const std::string &TagName) const noexcept;
  bool assignTagTo(const std::string &TagName,
                   const std::string &ContactName) noexcept;
  bool removeTagFor(const std::string &TagName,
                    const std::string &ContactName) noexcept;
};
}  // namespace BCS
#endif  // BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
