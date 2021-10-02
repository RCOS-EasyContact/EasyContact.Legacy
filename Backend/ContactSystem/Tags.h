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
  void assignTagTo(const std::string &TagName, const std::string &ContactName) {
    _TAGS[TagName].insert(ContactName);
  }
  void removeTagFor(const std::string &ContactName){
    for (std::map<std::string, std::set<std::string>>::iterator i =
             _TAGS.begin();
         i != _TAGS.end(); ++i) {
i->second.erase(ContactName);
      }
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
  std::vector<std::string> getTagContains(const std::string &TagName) {
    std::vector<std::string> Result;
    const std::set<std::string> &T = _TAGS[TagName];
    for (std::set<std::string>::const_iterator i = T.begin(); i != T.end();
         ++i) {
      Result.push_back(*i);
    }
    return Result;
  }
  std::vector<std::string> getNameInTags(const std::string &ContactName) {
    std::vector<std::string> Result;
    for (std::map<std::string, std::set<std::string>>::const_iterator i =
             _TAGS.begin();
         i != _TAGS.end(); ++i) {
      for (std::set<std::string>::const_iterator N = i->second.begin();
           N != i->second.end(); ++N) {
        if (*N == ContactName) {
          Result.push_back(i->first);
          break;
        }
      }
    }
    return Result;
  }
};
} // namespace BCS
#endif // BACKEND_CONTACTSYSTEM_TAGS_H_
