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
#include "SingleUser.hpp"
// Global Representation
std::unordered_map<std::string,MCS::SingleUser> ActiveUsers;
int main(){
  SQLite::Database    DB3("UserData/.DEFAULT/Contacts.db3",SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
  DB3.exec("DROP TABLE emailadres");
DB3.exec("CREATE TABLE emailadres(RCSID TEXT PRIMARY KEY, EMAIL TEXT NOT NULL)");  
// DB3.exec("INSERT INTO emailadres VALUES('gongz3','gongz3@rpi.edu')");
}
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
