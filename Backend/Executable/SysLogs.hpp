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
namespace SYSLOG{
static void PrintException(const std::exception &Err){
time_t _TT;
        struct tm *_TI;
        time(&_TT);
        _TI = localtime(&_TT);
        std::cerr << asctime(_TI) << "Run-Time Exception: " << Err.what()
                  << std::endl;
}

}
#endif // BACKEND_EXECUTABLE_SYSLOGS_HPP_