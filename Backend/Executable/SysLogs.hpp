/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * SysLogs.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_EXECUTABLE_SYSLOGS_HPP_
#define BACKEND_EXECUTABLE_SYSLOGS_HPP_
// C++ Standard Library
#include <chrono>
#include <ctime>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
namespace SYSLOG {
inline static void PrintException(const std::exception &Err) {
  std::time_t timenow =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      std::string Buffer=std::move(std::ctime(&timenow));
      Buffer[Buffer.size()]=0;
  std::cerr << "<"<<Buffer << "> Run-Time Exception: " << Err.what()
            << std::endl;
}
template <typename... Args>
inline static void PrintRequest(Args &&...A) {
  std::stringstream BUFFER;
  (BUFFER << ... << A);
  std::time_t timenow =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::cout << std::ctime(&timenow) << "User Request: " << BUFFER.str()
            << std::endl;
}
}  // namespace SYSLOG
#endif  // BACKEND_EXECUTABLE_SYSLOGS_HPP_
