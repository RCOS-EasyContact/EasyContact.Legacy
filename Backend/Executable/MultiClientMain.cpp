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
// #include "../API/APIRouter.hpp"
#include "SingleUser.hpp"
#include "GlobalMutex.hpp"
// Global Representation
std::unordered_map<std::string, SingleUser> ActiveUsers;
int main() {
while(true){pause();}
}
#endif  // BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
