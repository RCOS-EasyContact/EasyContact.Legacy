/**
 * RCOS-EasyContact
 * EasyContact/Backend/src
 * SingleUser.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_SRC_SINGLEUSER_CPP_
#define BACKEND_SRC_SINGLEUSER_CPP_
#include <EasyContact/SingleUser.hpp>
SingleUser::SingleUser(const std::string& RCSID, const std::string& Password)
    : MailClient(RCSID, Password), SQLContacts(RCSID) {}
#endif  // BACKEND_SRC_SINGLEUSER_CPP_
