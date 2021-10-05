/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * MainExecutable.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_MAINEXECUTABLE_CPP_
#define BACKEND_MAINEXECUTABLE_CPP_
// EasyContact Header Files
#include "SignalHandler.h"
// Global Representation
// BCS::ContactBook *ContactBookSystem;
pthread_mutex_t CBS_Mutex;
int main() {
  // Reg Sigactions
  REG_SIGACTION();
  // Initilize Global Representation
  // ContactBookSystem = new BCS::ContactBook;
  CBS_Mutex = PTHREAD_MUTEX_INITIALIZER;
  // Create Pthreads for Each Function
  // pthread_create();
  // Main Executable Waits for Signal
  while (true) {
    pause();
  }
  std::cerr << "EasyContact: "
            << "Unexpected Behavior, Terminating..." << std::endl;
  exit(EXIT_FAILURE);
}
#endif  // BACKEND_MAINEXECUTABLE_CPP_
