/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * SignalHandler.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SIGNALHANDLER_H_
#define BACKEND_SIGNALHANDLER_H_
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include "ContactSystem/ContactBook.h"
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
    extern BCS::ContactBook *ContactBookSystem;
    delete ContactBookSystem;
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
#endif  //  BACKEND_SIGNALHANDLER_H_
