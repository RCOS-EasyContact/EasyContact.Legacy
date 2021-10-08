/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Books.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_BOOKS_CPP_
#define BACKEND_CONTACTSYSTEM_BOOKS_CPP_
#include "Books.hpp"
bool BCS::Books::newContact(const BCS::Key &NewContact) {
  return _DB.insert(NewContact).second;
}
bool BCS::Books::newTag(const std::string &TagName) {
  return (_TAGS
              .insert(std::pair<std::string, std::set<std::string>>(
                  TagName, std::set<std::string>()))
              .second) > 0;
}
bool BCS::Books::removeContact(const std::string &ExistContact) {
  clearTagFor(ExistContact);
  return (_DB.erase(BCS::Key(ExistContact, ""))) > 0;
}
bool BCS::Books::removeTag(const std::string &TagName) {
  return _TAGS.erase(TagName);
}
const std::set<BCS::Key> &BCS::Books::getAllContacts() { return _DB; }
std::set<std::string> BCS::Books::getAllTags() {
  std::set<std::string> Result;
  for (std::map<std::string, std::set<std::string>>::const_iterator i =
           _TAGS.begin();
       i != _TAGS.end(); ++i) {
    Result.insert(i->first);
  }
  return Result;
}
void BCS::Books::assignTagTo(const std::string &TagName,
                             const std::string &ContactName) {
  _TAGS[TagName].insert(ContactName);
}
void BCS::Books::removeTagFor(const std::string &TagName,
                              const std::string &ContactName) {
  _TAGS[TagName].erase(ContactName);
}
void BCS::Books::clearTagFor(const std::string &ContactName) {
  for (std::map<std::string, std::set<std::string>>::iterator i = _TAGS.begin();
       i != _TAGS.end(); ++i) {
    i->second.erase(ContactName);
  }
}

std::set<std::string> BCS::Books::getTagContains(const std::string &TagName) {
  std::set<std::string> Result;
  const std::set<std::string> &T = _TAGS[TagName];
  for (std::set<std::string>::const_iterator i = T.begin(); i != T.end(); ++i) {
    Result.insert(*i);
  }
  return Result;
}
std::set<std::string>
BCS::Books::getNameInTags(const std::string &ContactName) {
  std::set<std::string> Result;
  for (std::map<std::string, std::set<std::string>>::const_iterator i =
           _TAGS.begin();
       i != _TAGS.end(); ++i) {
    for (std::set<std::string>::const_iterator N = i->second.begin();
         N != i->second.end(); ++N) {
      if (*N == ContactName) {
        Result.insert(i->first);
        break;
      }
    }
  }
  return Result;
}
#endif  // BACKEND_CONTACTSYSTEM_BOOK_CPP_
