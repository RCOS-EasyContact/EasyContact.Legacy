/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * MultiClientMain.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
#define BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
// C Standard Library
#include <signal.h>
// C++ Standard Library
#include <iostream>
#include <mutex>
#include <thread>
// Standard Template Library
#include <unordered_map>
// EasyContact Header Files
#include "../API/APIRouter.hpp"
#include "../SQLContacts/Contacts.hpp"
#include "GlobalMutex.hpp"
// Global Representation
std::unordered_map<std::string, BCS::Contacts> ActiveUsers;
int main() {
  BCS::Contacts T("gongz3");
  T.newContact("Friend 01","frd01@noreply.io");
  T.newContact("Friend 02","frd02@noreply.io");
  T.newContact("Friend 03","frd03@noreply.io");
  T.removeContact("Friend 02");
  T.removeContact("Friend 03");
}
#endif  // BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
