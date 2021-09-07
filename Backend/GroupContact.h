#ifndef RCOS_EASYCONTACT_CXX_HEADER_GROUPCONTACT
#define RCOS_EASYCONTACT_CXX_HEADER_GROUPCONTACT
#include "Contact.h"
#include <iostream>
#include <map>
#include <string>
class GroupContact {
  std::string _NAME;
  std::map<short unsigned int, Contact> _GROUP;

public:
  GroupContact() = default();
  GroupContact()
};
#endif
