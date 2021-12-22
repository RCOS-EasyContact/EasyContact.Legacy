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
// EasyContact Header Files
#include <EasyContact/ColorfulOutput.hpp>
namespace SYSLOG {
inline static void PrintException(const std::exception &Err) noexcept {
  std::time_t timenow =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::string Buffer = std::move(std::ctime(&timenow));
  Buffer[Buffer.size() - 1] = 0;
  COLOR::Modifier TIME(COLOR::FG_GREEN);
  COLOR::Modifier ERROR(COLOR::FG_RED);
  COLOR::Modifier DEFAULT(COLOR::FG_DEFAULT);
  std::cerr << TIME << "<" << Buffer << "> " << ERROR
            << "Run-Time Exception: " << Err.what() << DEFAULT << std::endl
            << std::flush;
}
template <typename... FoldExpression>
inline static void PrintRequest(FoldExpression &&... Argv) noexcept {
  std::stringstream BUFFER;
  (BUFFER << ... << Argv);
  std::time_t timenow =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::string TimeBuffer = std::move(std::ctime(&timenow));
  TimeBuffer[TimeBuffer.size() - 1] = 0;
  std::cout << "<" << TimeBuffer << "> User Request: " << BUFFER.str()
            << std::endl
            << std::flush;
}
template <typename... FoldExpression>
inline static void PrintDebugMessage(FoldExpression &&... Argv) noexcept {
  std::stringstream BUFFER;
  (BUFFER << ... << Argv);
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
