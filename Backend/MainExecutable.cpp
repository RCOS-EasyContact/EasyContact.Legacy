/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * MainExecutable.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_MAINEXECUTABLE_CPP_
#define BACKEND_MAINEXECUTABLE_CPP_
#include "SignalHandler.h"
ContactBook *CBS;
int main() {
  REG_SIGACTION();
  CBS = new ContactBook;
  while (true) {
    pause();
  }
  std::cerr << "EasyContact: "
            << "Unexpected Behavior, Terminating..." << std::endl;
  exit(EXIT_FAILURE);
}
#endif  // BACKEND_MAINEXECUTABLE_CPP_
