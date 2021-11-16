/**
 * RCOS-EasyContact
 * EasyContact/Backend/src
 * DispatchQueue.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SRC_DISPATCHQUEUE_CPP_
#define BACKEND_SRC_DISPATCHQUEUE_CPP_
#include <EasyContact/DispatchQueue.hpp>
DispatchQueue::DispatchQueue(const size_t& NumThreads)
    : JobID(0), Threads(NumThreads) {
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
std::pair<size_t, size_t> DispatchQueue::Dispatch(
    const Functor& Operation) noexcept {
  std::unique_lock<std::mutex> u_Lock(Lock);
  Queue.push(Operation);
  u_Lock.unlock();
  CV.notify_one();
  return std::pair<size_t, size_t>(++JobID, Queue.size());
}
std::pair<size_t, size_t> DispatchQueue::Dispatch(
    Functor&& Operation) noexcept {
  std::unique_lock<std::mutex> u_Lock(Lock);
  Queue.push(std::move(Operation));
  u_Lock.unlock();
  CV.notify_one();
  return std::pair<size_t, size_t>(++JobID, Queue.size());
}
void DispatchQueue::Dispatch_Hander(void) {
  std::unique_lock<std::mutex> u_Lock(Lock);
  while (inServices) {
    // Wait Until Have Data or End Services
    CV.wait(u_Lock, [this] { return Queue.size() || !inServices; });
    //  After Wait, We Own the Lock
    if (inServices && Queue.size()) {
      Functor Job = std::move(Queue.front());
      Queue.pop();
      u_Lock.unlock();
      Job();
      u_Lock.lock();
    }
  }
}
#endif  // BACKEND_SRC_DISPATCHQUEUE_CPP_
