/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Tags.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_TAGS_CPP_
#define BACKEND_CONTACTSYSTEM_TAGS_CPP_
#include "Tags.h"
bool BCS::Tags::newTag(const std::string &TagName) {
  return _TAGS
      .insert(std::pair<std::string, std::set<std::string>>(
          TagName, std::set<std::string>()))
      .second;
}
bool BCS::Tags::removeTag(const std::string &TagName) {
  return _TAGS.erase(TagName);
}
void BCS::Tags::assignTagTo(const std::string &TagName,
                            const std::string &ContactName) {
  _TAGS[TagName].insert(ContactName);
}
void BCS::Tags::removeTagFor(const std::string &TagName,
                             const std::string &ContactName) {
  _TAGS[TagName].erase(ContactName);
}
void BCS::Tags::clearTagFor(const std::string &ContactName) {
  for (std::map<std::string, std::set<std::string>>::iterator i = _TAGS.begin();
       i != _TAGS.end(); ++i) {
    i->second.erase(ContactName);
  }
}
std::vector<std::string> BCS::Tags::getAllTags() {
  std::vector<std::string> Result;
  for (std::map<std::string, std::set<std::string>>::const_iterator i =
           _TAGS.begin();
       i != _TAGS.end(); ++i) {
    Result.push_back(i->first);
  }
  return Result;
}
std::vector<std::string> BCS::Tags::getTagContains(const std::string &TagName) {
  std::vector<std::string> Result;
  const std::set<std::string> &T = _TAGS[TagName];
  for (std::set<std::string>::const_iterator i = T.begin(); i != T.end(); ++i) {
    Result.push_back(*i);
  }
  return Result;
}
std::vector<std::string>
BCS::Tags::getNameInTags(const std::string &ContactName) {
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
#endif  // BACKEND_CONTACTSYSTEM_TAGS_CPP_
