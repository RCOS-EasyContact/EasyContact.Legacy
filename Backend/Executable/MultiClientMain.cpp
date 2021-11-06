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
#include <unordered_map>
// EasyContact Header Files
#include "../API/APIRouter.hpp"
#include "GlobalMutex.hpp"
#include "SingleUser.hpp"
#include "hv/HttpServer.h"
#include "hv/hv.h"
// Global Representation
std::unordered_map<std::string, SingleUser> ActiveUsers;
void Reg_APIServer() {
  try {
    http_server_t g_http_server;
    HttpService g_http_service;
    g_http_server.port = 3126;
    g_http_service.base_url = "";
    APIRouter::register_router(g_http_service);
    g_http_server.service = &g_http_service;
    http_server_run(&g_http_server, 0);
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
