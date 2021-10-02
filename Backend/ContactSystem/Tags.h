/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Key.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_TAGS_H_
#define BACKEND_CONTACTSYSTEM_TAGS_H_
// C++ Standard Library
#include <string>
#include <utility>
// Standard Template Library
#include <map>
#include <vector>
// EasyContact Headers
#include "Key.h"
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
class Tags {
  std::map<std::string, std::vector<Key>> _TAGS;

public:
  Tags() = default;
  bool newTag(const std::string &TagName) {
    return _TAGS
        .insert(std::pair<std::string, std::vector<Key>>(TagName,
                                                         std::vector<Key>()))
        .second;
  }
  bool removeTag(const std::string &TagName) { return _TAGS.erase(TagName); }
};
} // namespace BCS
#endif // BACKEND_CONTACTSYSTEM_TAGS_H_
