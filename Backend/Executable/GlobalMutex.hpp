/**
 * RCOS-EasyContact
 * EasyContact/Backend/Executable
 * GlobalMutex.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_EXECUTABLE_GLOBALMUTEX_HPP_
#define BACKEND_EXECUTABLE_GLOBALMUTEX_HPP_
// C++ Standard Library
#include <mutex>
/**
 * Template<T> Mutable Class
 * <GlobalMutex> Repersents
 * One Type <T> Data Block Stored on Heap,
 * Paired With A Mutex Lock
 */
template <typename T>
class GlobalMutex {
  T *pDATA;
  std::mutex Mutex;

 public:
  explicit GlobalMutex(T *pValue) : pDATA(pValue) {}
  ~GlobalMutex() { delete pDATA; }
  T &operator*() { Mutex.lock();return *pDATA; }
  T *operator->() { Mutex.lock();return pDATA; }
  void Unlock(){Mutex.unlock();}
};
#endif  // BACKEND_EXECUTABLE_GLOBALMUTEX_HPP_
