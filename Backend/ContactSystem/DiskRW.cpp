/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * DiskRW.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_DISKRW_CPP_
#define BACKEND_CONTACTSYSTEM_DISKRW_CPP_
#include "DiskRW.hpp"
void BDO::LoadFromDisk(const uint8_t &ElementsPerLine,
                       const std::string &FileName,
                       std::vector<std::vector<std::string>> &Data) {
  std::ifstream FILE;
  FILE.open(FileName);
  if (!FILE.is_open()) {
    std::cerr << "Run-time Warning: " << std::endl
              << "LoadFromDisk:"
              << "File Not Exist" << std : endl;
    return;
  }
  std::string line;
  while (getline(FILE, line)) {
    std::vector<std::string> OneLine;
    int start = 0;
    int end = 0;
    for (size_t i = 0; i < line.length() - 1; ++i) {
      char tmp1 = line[i];
      if (tmp1 != ',' && start == 0) {
        start = i;
      } else if ((tmp1 == ',' || tmp1 == '\n') && end == 0) {
        end = i - start;
      }
      if (start != 0 && end != 0) {
        std::string info = line.substr(start, end);
        start = 0;
        end = 0;
        OneLine.push_back(info);
      }
    }
    Data.push_back(OneLine);
  }
  FILE.close();
}
void BDO::SaveToDisk(const uint8_t &ElementsPerLine,
                     const std::string &FileName,
                     const std::vector<std::vector<std::string>> &Data) {
  std::ofstream file(FileName);
  if (file.is_open()) {
    for (size_t i = 0, i < Data.size(), ++i) {
      for (size_t j = 0, j < Data[i].size(), ++j) {
        for (size_t k = 0, k < Data[i][j].size(), ++k) {
          file << Data[i][j][k] << k == Data[i][j].size() - 1 ? '\n' : ',';
        }
      }
    }
  }
  file.close();
}
#endif  // BACKEND_CONTACTSYSTEM_DISKRW_CPP_
