/**
 * RCOS-EasyContact
 * EasyContact/Backend/DiskRW
 * DataReadWrite.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_DISKRW_DATAREADWRITE_HPP_
#define BACKEND_DISKRW_DATAREADWRITE_HPP_
// C++ Standard Library
#include <fstream>
#include <iostream>
#include <string>
// Standard Template Library
#include <vector>
namespace DRW {
/**
 * Load Data From Hard Disk
 * Data Stored in ".csv" Format
 * @param <std::string> : File Name
 * @param <std::vector<std::vector<std::string>>> : Data Read From File
 */
void LoadFromDisk(const std::string &FileName,
                  std::vector<std::vector<std::string>> &Data);
/**
 * Save Data To Hard Disk
 * Data Stored in ".csv" Format
 * @param <std::string> : File Name
 * @param <std::vector<std::vector<std::string>>> : Data to be Saved
 */
void SaveToDisk(const std::string &FileName,
                const std::vector<std::vector<std::string>> &Data);
}  // namespace DRW
#endif  // BACKEND_DISKRW_DATAREADWRITE_HPP_
