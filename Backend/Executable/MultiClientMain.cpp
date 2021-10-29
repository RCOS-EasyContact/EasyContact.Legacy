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
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
// C++ Standard Library
#include <iostream>
#include <mutex>
#include <thread>
// Standard Template Library
#include <unordered_map>
// EasyContact Header Files
// #include "../API/APIRouter.hpp"
#include "GlobalMutex.hpp"
#include "../SQLContacts/Contacts.hpp"
// Global Representation
std::unordered_map<std::string, BCS::Contacts> ActiveUsers;
int main() {
  const std::string RCSID = "gongz2";

  // MAIN
}

#if 0
SQLite::Database    DB3("UserData/.DEFAULT/Contacts.db3",SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
DB3.exec("CREATE TABLE tags(NAME TEXT PRIMARY KEY NOT NULL)");
#endif

#if 0
int main() {
  // Start API Thread
  // std::thread();
  while(true){
    // The Main Process Does Not Do Much
    // It Monitors Child Threads Activity
    pause();
  }
  // DRW::Read_UserContacts(&ContactBook);
  // DRW::Write_UserContacts(ContactBook);
  exit(EXIT_FAILURE);
}
#endif
#endif  // BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
