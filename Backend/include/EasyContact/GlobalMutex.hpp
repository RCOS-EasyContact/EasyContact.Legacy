/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * GlobalMutex.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_GLOBALMUTEX_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_GLOBALMUTEX_HPP_
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
  mutable std::mutex Mutex;

 public:
  explicit GlobalMutex(T *pValue) : pDATA(pValue) {}
  ~GlobalMutex() {
  Mutex.lock();
  delete pDATA;
  pDATA = nullptr;
  Mutex.unlock();
}
  T &operator*() { return *pDATA; }
  const T &operator*() const { return *pDATA; }
  T *operator->() { return pDATA; }
  const T *operator->() const { return pDATA; }
  void Lock() const { Mutex.lock(); }
  void Unlock() const { Mutex.unlock(); }
};
#endif  // BACKEND_INCLUDE_EASYCONTACT_GLOBALMUTEX_HPP_
