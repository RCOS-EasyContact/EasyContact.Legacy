/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * SysLogs.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_SYSLOGS_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_SYSLOGS_HPP_
// C++ Standard Library
#include <chrono>
#include <ctime>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
namespace SYSLOG {
inline static void PrintException(const std::exception &Err) noexcept {
  std::time_t timenow =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::string Buffer = std::move(std::ctime(&timenow));
  Buffer[Buffer.size() - 1] = 0;
  std::cerr << "<" << Buffer << "> Run-Time Exception: " << Err.what()
            << std::endl
            << std::flush;
}
template <typename... Args>
inline static void PrintRequest(Args &&...A) noexcept {
  std::stringstream BUFFER;
  (BUFFER << ... << A);
  std::time_t timenow =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::string TimeBuffer = std::move(std::ctime(&timenow));
  TimeBuffer[TimeBuffer.size() - 1] = 0;
  std::cout << "<" << TimeBuffer << "> User Request: " << BUFFER.str()
            << std::endl
            << std::flush;
}
template <typename... Args>
inline static void PrintDebugMessage(Args &&...A) noexcept {
  std::stringstream BUFFER;
  (BUFFER << ... << A);
  std::time_t timenow =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::string TimeBuffer = std::move(std::ctime(&timenow));
  TimeBuffer[TimeBuffer.size() - 1] = 0;
  std::cerr << "<" << TimeBuffer << "> Debug Output: " << BUFFER.str()
            << std::endl
            << std::flush;
}
}  // namespace SYSLOG
#endif  // BACKEND_INCLUDE_EASYCONTACT_SYSLOGS_HPP_
