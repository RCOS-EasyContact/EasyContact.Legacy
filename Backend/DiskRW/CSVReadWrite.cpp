/**
 * RCOS-EasyContact
 * EasyContact/Backend/DiskRW
 * CSVReadWrite.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_DISKRW_CSVREADWRITE_CPP_
#define BACKEND_DISKRW_CSVREADWRITE_CPP_
#include "CSVReadWrite.hpp"
void DRW::LoadFromDisk(const std::string &FileName,
                       std::vector<std::vector<std::string>> *Data) {
  std::ifstream FILE;
  FILE.open(FileName);
  if (!FILE.is_open()) {
    std::cerr << "Run-time Warning: " << std::endl
              << "LoadFromDisk:"
              << "File Not Exist" << std::endl;
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
    Data->push_back(OneLine);
  }
  FILE.close();
}
void DRW::SaveToDisk(const std::string &FileName,
                     const std::vector<std::vector<std::string>> &Data) {
  std::ofstream FILE(FileName);
  if (!FILE.is_open()) {
    std::cerr << "Run-time Warning: " << std::endl
              << "SaveFromDisk:"
              << "File Could Not Be Created" << std::endl;
    return;
  }
  for (std::vector<std::vector<std::string>>::const_iterator A = Data.begin();
       A != Data.end(); ++A) {
    for (std::vector<std::string>::const_iterator B = A->begin();
         B != A->end();) {
      FILE << *B << (++B == A->end() ? "\n" : ",");
    }
  }
  FILE.close();
}
#endif  // BACKEND_DISKRW_CSVREADWRITE_CPP_
