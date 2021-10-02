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
#include <set>
#include <vector>
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
class Tags {
  std::map<std::string, std::set<std::string>> _TAGS;

public:
  Tags() = default;
  bool newTag(const std::string &TagName) {
    return _TAGS
        .insert(std::pair<std::string, std::set<std::string>>(
            TagName, std::set<std::string>()))
        .second;
  }
  bool removeTag(const std::string &TagName) { return _TAGS.erase(TagName); }
  void assignTag(const std::string &TagName, const std::string &ContactName) {
    _TAGS[TagName].insert(ContactName);
  }
  std::vector<std::string> getAllTags() {
    std::vector<std::string> Result;
    for (std::map<std::string, std::set<std::string>>::const_iterator i =
             _TAGS.begin();
         i != _TAGS.end(); ++i) {
      Result.push_back(i->first);
    }
    return Result;
  }
    std::vector<std::string> getTagsByName(const std::string&ContactName) {
    std::vector<std::string> Result;
    return Result;
  }
};
} // namespace BCS
#endif // BACKEND_CONTACTSYSTEM_TAGS_H_
