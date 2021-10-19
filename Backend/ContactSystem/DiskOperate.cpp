/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * DiskOperate.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_DISKOPERATE_CPP_
#define BACKEND_CONTACTSYSTEM_DISKOPERATE_CPP_
#include "DiskOperate.hpp"
void BDO::LoadFromDisk(const uint8_t &ElementsPerLine,
                       const std::string &FileName,
                       std::vector<std::vector<std::string>> &Data) {
  std::ifstream file;
  file.open(FileName);
  // read file
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      // A single contact
      std::vector<std::string> contact;
      // Store info position
      int start = 0;
      int end = 0;
      // Run through each character
      for (unsigned int i = 0; i < line.length() - 1; ++i) {
        // get current character
        char tmp1 = line[i];
        // If the Contact info start
        if (tmp1 != ',' && start == 0) {
          start = i;
          // If Contact info end
        } else if ((tmp1 == ',' || tmp1 == '\n') && end == 0) {
          end = i - start;
        }
        // Locate info
        if (start != 0 && end != 0) {
          std::string info = line.substr(start, end);
          start = 0;
          end = 0;
          // Add new contact info into contact vector
          contact.push_back(info);
        }
      }
      Data.push_back(contact);
    }
  }
  file.close();
}
void BDO::SaveToDisk(const uint8_t &ElementsPerLine,
                     const std::string &FileName,
                     const std::vector<std::vector<std::string>> &Data) {
  std::ofstream file(FileName);
  if (file.is_open()) {
    for (int i = 0, i < Data.size(), ++i) {
      for (int j = 0, j < Data[i].size(), ++j) {
        for (int k = 0, k < Data[i][j].size(), ++k) {
          file << Data[i][j][k] << k == Data[i][j].size() - 1 ? '\n' : ',';
        }
      }
    }
  }
  file.close();
}
#endif  // BACKEND_CONTACTSYSTEM_DISKOPERATE_CPP_
