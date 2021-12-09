/**
 * RCOS-EasyContact
 * EasyContact/Backend/src
 * MailClient.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SRC_MAILCLIENT_CPP_
#define BACKEND_SRC_MAILCLIENT_CPP_
// C++ Standard Library
#include <fstream>
// VMime Library
#include <vmime/vmime.hpp>
// EasyContact Header Files
#include <EasyContact/SysLogs.hpp>
#include <EasyContact/MailClient.hpp>
static const char* const EmailHostname="@rpi.edu";
static const char* const UserDataLocation = "data/";
static const char* const EmailServerAddress = "mail.rpi.edu";
BMC::MailClient::MailClient(const std::string& RCSID, const std::string& Password)
:_RCSID(RCSID),_PASSWORD(Password),_EMAILADDRESS(RCSID+EmailHostname),_NICKNAME(RCSID){}
#endif  // BACKEND_SRC_MAILCLIENT_CPP_
