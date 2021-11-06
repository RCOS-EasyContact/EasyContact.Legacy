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
#include "hv/HttpServer.h"
#include "hv/hv.h"
#include "../API/APIRouter.hpp"
#include "SingleUser.hpp"
#include "GlobalMutex.hpp"
// Global Representation
std::unordered_map<std::string, SingleUser> ActiveUsers;
http_server_t g_http_server;
HttpService g_http_service;
int main() {
  g_http_server.port=3126;
  g_http_service.base_url="";
  APIRouter::register_router(g_http_service);
  g_http_server.service=&g_http_service;
  http_server_run(&g_http_server,0);
while(true){pause();}
}
#endif  // BACKEND_EXECUTABLE_MULTICLIENTMAIN_CPP_
