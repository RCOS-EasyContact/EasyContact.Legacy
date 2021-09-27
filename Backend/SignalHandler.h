/**
 * RCOS-EasyContact
 * EasyContact/Backend
 * SignalHandler.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SIGNALHANDLER_H_
#define BACKEND_SIGNALHANDLER_H_
#include <iostream>
#include <signal.h>
/**
 * Handles Different Signals
 */
void SIG_HANDLER(int Argv) {
  if (Argv == SIGCHLD) {
    std::cout << "CHLD" << std::endl;
  }
  if (Argv == SIGUSR1) {
    std::cout << "USR1" << std::endl;
  }
  if (Argv == SIGINT) {
    std::cout << "Shutdown" << std::endl;
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
#endif // BACKEND_SIGNALHANDLER_H_