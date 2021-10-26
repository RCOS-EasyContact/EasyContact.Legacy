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
// EasyContact Header Files
// #include "../API/APIRouter.hpp"
#include "../ContactSystem/Books.hpp"
#include "../ContactSystem/Key.hpp"
#include "../DiskRW/CSVReadWrite.hpp"
#include "../DiskRW/DatabaseReadWrite.hpp"
#include "GlobalMutex.hpp"
// Global Representation
std::string Global_CurrentUserRCSID{"Empty"};
int main() {
  // Start API Thread
  // std::thread();
  while(true){
    // Wait For A User Login
    pause();
  }
  DRW::Read_UserContacts(&ContactBook);
  DRW::Write_UserContacts(ContactBook);
  exit(EXIT_FAILURE);
}
#endif  // BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
