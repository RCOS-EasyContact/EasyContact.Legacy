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
 * EasyContact Custom Namespace
 * GM : GlobalMutex Template Class
 */
namespace GM {
/**
 * Template<T> Mutable Class
 * <GlobalMutex> Repersents
 * One Type <T> Data Block Stored on Heap,
 * Paired With A Mutex Lock
 */
template <typename T> class GlobalMutex {
  T *pDATA;

 public:
  std::mutex Mutex;
  explicit GlobalMutex(T *pValue) : pDATA(pValue) {}
  ~GlobalMutex() { delete pDATA; }
  T &operator*() { return *pDATA; }
  T *operator->() { return pDATA; }
};
}  // namespace GM
#endif  // BACKEND_EXECUTABLE_GLOBALMUTEX_HPP_
