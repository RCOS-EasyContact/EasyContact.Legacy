/**
 * RCOS-EasyContact
 * EasyContact/Backend/src
 * GlobalMutex.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SRC_GLOBALMUTEX_CPP_
#define BACKEND_SRC_GLOBALMUTEX_CPP_
#include <EasyContact/GlobalMutex.hpp>
GlobalMutex::GlobalMutex(T *pValue) : pDATA(pValue) {}
GlobalMutex::~GlobalMutex(){
      Mutex.lock();
    delete pDATA;
    pDATA = nullptr;
    Mutex.unlock();
}
#endif // BACKEND_SRC_GLOBALMUTEX_CPP_
