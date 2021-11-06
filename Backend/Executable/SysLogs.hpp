/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * SysLogs.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_EXECUTABLE_SYSLOGS_HPP_
#define BACKEND_EXECUTABLE_SYSLOGS_HPP_
// C++ Standard Library
#include <ctime>
#include <chrono>
#include <exception>
#include <iostream>
namespace SYSLOG {
static void PrintException(const std::exception &Err) {
    std::time_t timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::cerr <<  std::ctime(&timenow) << "Run-Time Exception: " << Err.what()
            << std::endl;
}
}  // namespace SYSLOG
#endif  // BACKEND_EXECUTABLE_SYSLOGS_HPP_
