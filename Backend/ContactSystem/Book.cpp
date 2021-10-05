/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Book.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_BOOK_CPP_
#define BACKEND_CONTACTSYSTEM_BOOK_CPP_
#include "Book.hpp"
bool BCS::Book::addContact(const Key &NewContact) {
  return _BOOK.insert(NewContact).second;
}
void BCS::Book::removeContact(const std::string &ExistContact) {
  _BOOK.erase(Key(ExistContact, ""));
  _TAGS.clearTagFor(ExistContact);
}
std::vector<BCS::Key> BCS::Book::getAllContacts() {
  std::vector<Key> RESULT;
  for (std::set<Key>::const_iterator i = _BOOK.begin(); i != _BOOK.end(); ++i) {
    RESULT.push_back(*i);
  }
  return RESULT;
}
#endif // BACKEND_CONTACTSYSTEM_BOOK_CPP_
