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
#include <mutex>
#include <thread>
// Standard Template Library
#include <queue>
#include <utility>
#include <vector>
class DispatchQueue {
  using Functor = std::function<void(void)>;

 private:
  size_t JobID;
  std::mutex Lock;
  std::vector<std::thread> Threads;
  std::queue<Functor> Queue;
  std::condition_variable CV;
  bool inServices = true;
  void Dispatch_Hander(void);

 public:
  /**
   * Default Class Constructor
   * @param NumThreads : Number of Threads to Create
   */
  explicit DispatchQueue(const size_t& NumThreads);
  /**
   * Default Class Destructor
   */
  ~DispatchQueue();
  /**
   * Add Task to Dispatch Queue
   * @param Operation : Task Expressed in Lambda Expression
   * @return std::pair<size_t, size_t> : Your Task ID, Number of Tasks Before
   * Your Task
   */
  std::pair<size_t, size_t> Dispatch(const Functor& Operation);
  /**
   * Add Task to Dispatch Queue
   * @param Operation : Task Expressed in Lambda Expression
   * @return std::pair<size_t, size_t> : Your Task ID, Number of Tasks Before
   * Your Task
   */
  std::pair<size_t, size_t> Dispatch(Functor&& Operation);
  /**
   * This Funtion Call Is Not Allowed &
   * Will Delete Left Hand Side Instance
   * @param RHS : Another Instance of Current Class
   */
  DispatchQueue(const DispatchQueue& RHS) = delete;
  /**
   * This Funtion Call Is Not Allowed &
   * Will Delete Left Hand Side Instance
   * @param RHS : Another Instance of Current Class
   * @return DispatchQueue : Reference to SELF
   */
  DispatchQueue& operator=(const DispatchQueue& RHS) = delete;
  /**
   * This Funtion Call Is Not Allowed &
   * Will Delete Left Hand Side Instance
   * @param RHS : Another Instance of Current Class
   */
  DispatchQueue(DispatchQueue&& RHS) = delete;
  /**
   * This Funtion Call Is Not Allowed &
   * Will Delete Left Hand Side Instance
   * @param RHS : Another Instance of Current Class
   * @return DispatchQueue : Reference to SELF
   */
  DispatchQueue& operator=(DispatchQueue&& RHS) = delete;
};
#endif  // BACKEND_INCLUDE_EASYCONTACT_DISPATCHQUEUE_HPP_
