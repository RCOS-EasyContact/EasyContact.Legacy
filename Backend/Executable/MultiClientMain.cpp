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
  std::string RCSID="gongz3";
if(!std::filesystem::directory_entry("UserData/"+RCSID).is_directory()){
       std::filesystem::create_directory("UserData/"+RCSID);
       copy_file( std::filesystem::directory_entry("UserData/.DEFAULT/Contacts.db3"),
                std::filesystem::directory_entry("UserData/"+RCSID+"/Contacts.db3"));
       }
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
