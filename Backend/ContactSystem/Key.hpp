/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Key.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_KEY_HPP_
#define BACKEND_CONTACTSYSTEM_KEY_HPP_
// C++ Standard Library
#include <string>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
/**
 * Immutable Class
 * <Key> Repersents
 * One Contact Information
 * -----   -----   -----
 * No Duplicate Names Are Allowed
 */
class Key {
 public:
  /**
   * <std::string> Represents
   * Contact Name
   */
  const std::string Name;
  /**
   * <std::string> Represents
   * Contact Email Address
   */
  const std::string Address;
  /**
   * Default Class Constructor
   * @param <std::string> : Contact Name to be Stored
   * @param <std::string> : Email Address to be Stored
   */
  explicit Key(const std::string &ContactName,
               const std::string &ContactAddress)
      : Name(ContactName), Address(ContactAddress) {}
  /**
   * Compare Different Instances
   * No Duplicate Names Are Allowed
   * @param <Key> : Another Instance of <Key> Class
   * @return <bool> : Compares Between Two Instances
   */
  [[nodiscard]] inline bool operator==(const Key &Instance) {
    return this->Name == Instance.Name;
  }
  /**
   * Compare Different Instances
   * No Duplicate Names Are Allowed
   * @param <std::string> : Contact Name of Another Instance
   * @return <bool> : Compares Between Two Instances
   */
  [[nodiscard]] inline bool operator==(const std::string &ContactName) {
    return this->Name == ContactName;
  }
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_KEY_HPP_
