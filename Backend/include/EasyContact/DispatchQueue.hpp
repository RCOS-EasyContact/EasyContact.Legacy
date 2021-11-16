/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * DispatchQueue.hpp
 * Copyright [2021] <RCOS-EasyContact>
 * Reference:
 * https://embeddedartistry.com/blog/2017/02/08/implementing-an-asynchronous-dispatch-queue/
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_DISPATCHQUEUE_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_DISPATCHQUEUE_HPP_
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
#include <EasyContact/SingleUser.hpp>
class DispatchQueue {
  typedef std::function<void(void)> Functor;

 private:
 size_t JobID;
  std::mutex Lock;
  std::vector<std::thread> Threads;
  std::queue<Functor> Queue;
  std::condition_variable CV;
  bool inServices = true;
  void Dispatch_Hander(void);

 public:
  explicit DispatchQueue(const size_t& NumThreads);
  ~DispatchQueue();
  std::pair<size_t,size_t> Dispatch(const Functor& Operation)noexcept;
  std::pair<size_t,size_t> Dispatch(Functor&& Operation)noexcept;
  DispatchQueue(const DispatchQueue& RHS) = delete;
  DispatchQueue& operator=(const DispatchQueue& RHS) = delete;
  DispatchQueue(DispatchQueue&& RHS) = delete;
  DispatchQueue& operator=(DispatchQueue&& RHS) = delete;
};
#endif  // BACKEND_INCLUDE_EASYCONTACT_DISPATCHQUEUE_HPP_
