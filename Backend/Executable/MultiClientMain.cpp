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
// C++ Standard Library
#include <iostream>
#include <mutex>
#include <thread>
// Standard Template Library
#include <utility>
#include <unordered_map>
// EasyContact Header Files
#include "../API/APIRouter.hpp"
#include "GlobalMutex.hpp"
#include "SingleUser.hpp"
#include "hv/HttpServer.h"
#include "hv/hv.h"
// Global Representation
std::unordered_map<std::string, SingleUser> g_ActiveUsers;
http_server_t g_Http_Server;
HttpService g_Http_Service;
void Reg_APIServer() {
  try {
    g_Http_Server.port = 3126;
    g_Http_Service.base_url = "";
    APIRouter::register_router(g_Http_Service);
    g_Http_Server.service = &g_Http_Service;
    http_server_run(&g_Http_Server, 0);
  } catch (std::exception& Err) {
    std::cerr << "Run-Time Exception <APIRouter> := " << Err.what()
              << std::endl;
    exit(EXIT_FAILURE);
  }
}
int main() {
  Reg_APIServer();
  while (true) {
    pause();
  }
}
#endif  // BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
