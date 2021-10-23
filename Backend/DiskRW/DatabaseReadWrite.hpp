/**
 * RCOS-EasyContact
 * EasyContact/Backend/DiskRW
 * DatabaseReadWrite.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_DISKRW_DATABASEREADWRITE_HPP_
#define BACKEND_DISKRW_DATABASEREADWRITE_HPP_
// C++ Standard Library
#include <iostream>
#include <string>
// Standard Template Library
#include <unordered_set>
#include <vector>
// EasyContact Header Files
#include "../ContactSystem/Books.hpp"
#include "../ContactSystem/Key.hpp"
#include "../Executable/GlobalMutex.hpp"
#include "CSVReadWrite.hpp"
namespace DRW {
void Read_UserContacts(GlobalMutex<BCS::Books>* ContactBook);
void Write_UserContacts(const GlobalMutex<BCS::Books>& ContactBook);
}  // namespace DRW
#endif  // BACKEND_DISKRW_DATABASEREADWRITE_HPP_
