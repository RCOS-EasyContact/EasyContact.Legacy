/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * DispatchQueue.hpp
 * Copyright [2021] <RCOS-EasyContact>
 * Reference:
 * https://embeddedartistry.com/blog/2017/02/08/implementing-an-asynchronous-dispatch-queue/
 */
#ifndef BACKEND_EXECUTABLE_DISPATCHQUEUE_HPP_
#define BACKEND_EXECUTABLE_DISPATCHQUEUE_HPP_
// C++ Standard Library
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
// Standard Template Library
#include <queue>
#include <utility>
#include <vector>
// EasyContact Header Files
#include "../Executable/SingleUser.hpp"
class DispatchQueue {
  typedef SingleUser ParamType;
  typedef std::function<void(ParamType)> Functor;
  typedef std::pair<ParamType, Functor> DQPair;

 private:
  std::mutex Lock;
  std::vector<std::thread> Threads;
  std::queue<std::pair<ParamType, Functor>> Queue;
  std::condition_variable CV;
  bool inServices = true;
  void Dispatch_Hander(void);

 public:
  explicit DispatchQueue(const size_t& NumThreads);
  ~DispatchQueue();
  void Dispatch(const ParamType& Param, const Functor& Operation);
  void Dispatch(ParamType&& Param, Functor&& Operation);
  DispatchQueue(const DispatchQueue& RHS) = delete;
  DispatchQueue& operator=(const DispatchQueue& RHS) = delete;
  DispatchQueue(DispatchQueue&& RHS) = delete;
  DispatchQueue& operator=(DispatchQueue&& RHS) = delete;
};
#endif  // BACKEND_EXECUTABLE_DISPATCHQUEUE_HPP_
