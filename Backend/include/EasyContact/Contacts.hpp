/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * Contacts.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
// C++ Standard Library
#include <string>
#include <vector>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
/**
 * Create A User Data Directory If Such Directory
 * Does Not Exist Already
 * @param DirName : Name Of The Directory
 */
void CreateDirectory(const std::string &DirName) noexcept;
class Contacts {
 private:
  const std::string RCSID;

 public:
  /**
   * Default Class Constructor
   * @param newRCSID : RCSID For The New Database
   */
  explicit Contacts(const std::string &newRCSID);
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
   * Remove A Existing Group Tag From Database
   * @param TagName : Name Of The Tag To Be Removed
   * @return bool : Operation Successfulness
   */
  bool removeTag(const std::string &TagName) noexcept;
  /**
   * Get Email Address Of A Existing Contact
   * @param Name : Name Of The Contact
   * @return std::string : Email Address Of The Contact
   */
  [[nodiscard]] std::string getEmailAddress(
      const std::string &Name) const noexcept;
  /**
   * Get Names Of All Saved Contacts
   * @return std::vector<std::string> : Names Of All Saved Contacts
   */
  [[nodiscard]] std::vector<std::string> getAllNames() const noexcept;
  /**
   * Get Names Of All Tag Groups
   * @return std::vector<std::string> : Names Of All Tag Groups
   */
  [[nodiscard]] std::vector<std::string> getAllTags() const noexcept;
  /**
   * Get Names Of All Contacts Within One Tag Group
   * @param TagName : Name Of The Tag
   * @return std::vector<std::string> : Names Of All Contacts Within The Group
   */
  [[nodiscard]] std::vector<std::string> getTagContains(
      const std::string &TagName) const noexcept;
  /**
   * Assign One Tag To One Contact
   * @param TagName : Name Of The Group Tag
   * @param ContactName : Name Of The Contact
   * @return bool : Operation Successfulness
   */
  bool assignTagTo(const std::string &TagName,
                   const std::string &ContactName) noexcept;
  /**
   * Remove One Tag From One Contact
   * @param TagName : Name Of The Group Tag
   * @param ContactName : Name Of The Contact
   * @return bool : Operation Successfulness
   */
  bool removeTagFor(const std::string &TagName,
                    const std::string &ContactName) noexcept;

                    public:
                     /**
   * This Funtion Call Is Not Allowed &
   * Will Delete Left Hand Side Instance
   * @param RHS : Another Instance of Current Class
   */
                    Contacts(const Contacts& RHS)=delete;
                      /**
   * This Funtion Call Is Not Allowed &
   * Will Delete Left Hand Side Instance
   * @param RHS : Another Instance of Current Class
   * @return DispatchQueue : Reference to SELF
   */
                    Contacts& operator=(const Contacts& RHS)=delete;
                     /**
   * This Funtion Call Is Not Allowed &
   * Will Delete Left Hand Side Instance
   * @param RHS : Another Instance of Current Class
   */
                    Contacts(Contacts&& RHS)=delete;
                    /**
   * This Funtion Call Is Not Allowed &
   * Will Delete Left Hand Side Instance
   * @param RHS : Another Instance of Current Class
   * @return DispatchQueue : Reference to SELF
   */
                    Contacts& operator=(Contacts&& RHS)=delete;
};
}  // namespace BCS
#endif  // BACKEND_INCLUDE_EASYCONTACT_CONTACTS_HPP_
