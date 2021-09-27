/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * MainExecutable.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_MAINEXECUTABLE_CPP_
#define BACKEND_MAINEXECUTABLE_CPP_
#include <stdlib.h>
#include "SignalHandler.h"
#include <unistd.h>

int main(){
  std::cout<<"Pid: "<<getpid()<<std::endl;
  REG_SIGACTION();
  while(true){pause();}
  exit(EXIT_SUCCESS);
}
#endif // BACKEND_MAINEXECUTABLE_CPP_