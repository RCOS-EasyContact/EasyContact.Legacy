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
#include <time.h>
// C++ Standard Library
#include <iostream>
#include <mutex>
#include <thread>
// Standard Template Library
#include <unordered_map>
#include <utility>
#include <queue>
// Libhv Library
#include "hv/HttpServer.h"
#include "hv/hv.h"
// EasyContact Header Files
#include "../API/APIRouter.hpp"
#include "GlobalMutex.hpp"
#include "SingleUser.hpp"
#include "StreamProcessor.hpp"
#include "SysLogs.hpp"
// Project Defines
#define LISTEN_PORT 3126
#define MAX_PROCESSORS 2
// Global Representation
std::unordered_map<std::string, SingleUser> g_ActiveUsers;
GlobalMutex<std::queue<std::string>> g_TaskQueue(new std::queue<std::string>);
http_server_t g_Http_Server;
HttpService g_Http_Service;
void Reg_Processor(){

}
void Reg_APIServer() {
  try {
    g_Http_Server.port = LISTEN_PORT;
    g_Http_Service.base_url = "";
    APIRouter::register_router(&g_Http_Service);
    g_Http_Server.service = &g_Http_Service;
    http_server_run(&g_Http_Server, 0);
  } catch (std::exception& Err) {
        SYSLOG::PrintException(Err);
    exit(EXIT_FAILURE);
  }
}
int main() {
  // Generate Random Seed
  srand(time(0));
  // Start Stream Processors
  Reg_Processor();
  // Start API Server
  Reg_APIServer();
  // Wait
  while (true) {
    pause();
  }
}
#endif  // BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
