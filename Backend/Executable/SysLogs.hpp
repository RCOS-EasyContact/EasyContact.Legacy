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
#include <exception>
#include <iostream>
namespace SYSLOG {
static void PrintException(const std::exception &Err) {
  time_t _TT;
  struct tm *_TI;
  char _B1[26];
  char _B2[26];
  time(&_TT);
  _TI = localtime_r(&_TT, &_B1);
  std::cerr << asctime_r(_TI, &_B2) << "Run-Time Exception: " << Err.what()
            << std::endl;
}
}  // namespace SYSLOG
#endif  // BACKEND_EXECUTABLE_SYSLOGS_HPP_
