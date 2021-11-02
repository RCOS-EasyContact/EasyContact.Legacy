/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * SingleUser.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_EXECUTABLE_SINGLEUSER_HPP
#define BACKEND_EXECUTABLE_SINGLEUSER_HPP
// C++ Standard Library
// EasyContact Header Files
#include "../MailClient/MailClient.hpp"
#include "../SQLContacts/Contacts.hpp"
class SingleUser{
public:
BMC::MailClient MailClient;
BCS::Contacts SQLContacts;
explicit SignleUser(const std::string &RCSID,const std::string& Password):MailClient(RCSID,Password),SQLContacts(RCSID){}

};
#endif // BACKEND_EXECUTABLE_SINGLEUSER_HPP