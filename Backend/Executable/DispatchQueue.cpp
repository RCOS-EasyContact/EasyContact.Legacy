/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * DispatchQueue.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_EXECUTABLE_DISPATCHQUEUE_CPP_
#define BACKEND_EXECUTABLE_DISPATCHQUEUE_CPP_
#include "DispatchQueue.hpp"
DispatchQueue::DispatchQueue(const size_t& NumThreads) : Threads(NumThreads) {
  for (size_t i = 0; i < Threads.size(); ++i) {
    Threads[i] = std::thread(&DispatchQueue::Dispatch_Hander, this);
  }
}
DispatchQueue::~DispatchQueue() {
  // Signal Dispatch Threads that
  // It is Time to Wrap Up
  std::unique_lock<std::mutex> u_Lock(Lock);
  inServices = false;
  u_Lock.unlock();
  CV.notify_all();
  // Wait for Threads to Finish
  for (size_t i = 0; i < Threads.size(); ++i) {
    if (Threads[i].joinable()) {
      Threads[i].join();
    }
  }
}
void DispatchQueue::Dispatch(const Functor& Operation) {
  std::unique_lock<std::mutex> u_Lock(Lock);
  Queue.push(Operation);
  u_Lock.unlock();
  CV.notify_one();
}
void DispatchQueue::Dispatch(Functor&& Operation) {
  std::unique_lock<std::mutex> u_Lock(Lock);
  Queue.push(std::move(Operation));
  u_Lock.unlock();
  CV.notify_one();
}
void DispatchQueue::Dispatch_Hander(void) {
  std::unique_lock<std::mutex> u_Lock(Lock);
  while (inServices) {
    // Wait Until Have Data or End Services
    CV.wait(u_Lock, [this] { return Queue.size() || !inServices; });
    //  After Wait, We Own the Lock
    if (inServices && Queue.size()) {
      auto Operation = std::move(Queue.front());
      Queue.pop();
      u_Lock.unlock();
      Operation();
      u_Lock.lock();
    }
  }
}
#endif  // BACKEND_EXECUTABLE_DISPATCHQUEUE_CPP_
