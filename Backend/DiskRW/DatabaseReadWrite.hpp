/**
 * RCOS-EasyContact
 * EasyContact/Backend/DiskRW
 * DatabaseReadWrite.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_DISKRW_DATABASEREADWRITE_HPP_
#define BACKEND_DISKRW_DATABASEREADWRITE_HPP_
// C++ Standard Library
#include <string>
// EasyContact Header Files
#include "../ContactSystem/Books.hpp"
#include "../ContactSystem/Key.hpp"
#include "CSVReadWrite.hpp"
namespace DRW {
  void Read_UserContacts();
  void Write_UserContacts();
}
#endif // BACKEND_DISKRW_DATABASEREADWRITE_HPP_