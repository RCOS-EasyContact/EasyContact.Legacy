/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * DiskOperate.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_DISKOPERATE_HPP_
#define BACKEND_CONTACTSYSTEM_DISKOPERATE_HPP_
// C++ Standard Library
#include <fstream>
#include <string>
// Standard Template Library
#include <vector>
namespace BDO {
/**
 * Load Data From Hard Disk
 * Data Stored in .csv Format
 * @param <uint8_t> : Elements Per Line
 * @param <std::string> : File Name
 * @return <std::vector<std::vector<std::string>>> : Data Read From File
 */
std::vector<std::vector<std::string>> LoadFromDisk(const uint8_t &ElementsPerLine,
                                                   const std::string &FileName);
/**
 * Save Data To Hard Disk
 * Data Stored in .csv Format
 * @param <uint8_t> : Elements Per Line
 * @param <std::string> : File Name
 * @param <std::vector<std::string>> : Data to be Saved
 */
void SaveToDisk(const uint8_t &ElementsPerLine, const std::string &FileName,
                const std::vector<std::string> &Data);
}  // namespace BDO
#endif  // BACKEND_CONTACTSYSTEM_DISKOPERATE_HPP_
