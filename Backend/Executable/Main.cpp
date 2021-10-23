/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * Main.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_EXECUTABLE_MAIN_CPP_
#define BACKEND_EXECUTABLE_MAIN_CPP_
// C Standard Library
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
// C++ Standard Library
#include <iostream>
#include <mutex>
#include <thread>
// EasyContact Header Files
// #include "../API/APIRouter.hpp"
#include "../ContactSystem/Books.hpp"
#include "../ContactSystem/Key.hpp"
#include "../DiskRW/CSVReadWrite.hpp"
#include "GlobalMutex.hpp"
// Global Representation
GlobalMutex<BCS::Books> ContactBook(new BCS::Books);
/**
 * Handles Different Signals
 */
void SIG_HANDLER(int Argv) {
  if (Argv == SIGCHLD) {
    pid_t ChildPID = 0;
    int ChildStatus = 0;
    while ((ChildPID = waitpid(-1, &ChildStatus, WNOHANG)) > 0) {
      if (WIFSIGNALED(ChildStatus)) {
        std::cerr << "EasyContact: "
                  << "Sub-Module Terminate Unexpectedly, "
                  << "Quitting Main Executable" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
    std::cout << "EasyContact: "
              << "All Sub-Modules are Working Normal" << std::endl;
  }
  if (Argv == SIGUSR1) {
    std::cout << "USR1" << std::endl;
  }
  if (Argv == SIGINT) {
    std::cout << "EasyContact: "
              << "Received Shutdown Signal" << std::endl;
    std::cout << "EasyContact: "
              << "Saving Information to Local Disk" << std::endl;
    // extern BCS::ContactBook *ContactBookSystem;
    // delete ContactBookSystem;
    std::cout << "EasyContact: "
              << "All Done, Thanks for Using" << std::endl;
    exit(EXIT_SUCCESS);
  }
}
/**
 * Register Variety of Signals to Signal Handler
 */
void REG_SIGACTION() {
  struct sigaction SIG_ACTION;
  SIG_ACTION.sa_handler = SIG_HANDLER;
  SIG_ACTION.sa_flags = 0;
  sigemptyset(&SIG_ACTION.sa_mask);
  sigaction(SIGCHLD, &SIG_ACTION, 0);
  sigaction(SIGUSR1, &SIG_ACTION, 0);
  sigaction(SIGINT, &SIG_ACTION, 0);
}
int main() {
  // Reg Sigactions
  REG_SIGACTION();
  // Create Pthreads for Each Function
  // std::thread();
  // Main Executable Waits for Signal
  while (true) {
    pause();
  }
  std::cerr << "EasyContact: "
            << "Unexpected Behavior, Terminating..." << std::endl;
  exit(EXIT_FAILURE);
}
#endif  // BACKEND_EXECUTABLE_MAIN_CPP_
