/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * DispatchQueue.hpp
 * Copyright [2021] <RCOS-EasyContact>
 * Reference: https://embeddedartistry.com/blog/2017/02/08/implementing-an-asynchronous-dispatch-queue/
 */
#ifndef BACKEND_EXECUTABLE_DISPATCHQUEUE_HPP_
#define BACKEND_EXECUTABLE_DISPATCHQUEUE_HPP_
// C++ Standard Library
#include <string>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
// Standard Template Library
#include <queue>
#include <vector>
class DispatchQueue{
  typedef std::function<void(void)> fp_t;
  private:
  std::mutex Lock;
  std::vector<std::thread> Threads;
std::queue<fp_t> Queue;
std::condition_variable CV;
bool inServices=true;
void Dispatch_Hander(void);

public:
explicit DispatchQueue(const size_t & NumThreads );
~DispatchQueue();
  void Dispatch(const fp_t& Operation);
  void Dispatch(fp_t&& Operation);
  DispatchQueue(const DispatchQueue& RHS)=delete;
DispatchQueue& operator=(const DispatchQueue& RHS)=delete;
  DispatchQueue( DispatchQueue&& RHS)=delete;
DispatchQueue& operator=( DispatchQueue&& RHS)=delete;
};
#endif // BACKEND_EXECUTABLE_DISPATCHQUEUE_HPP_
