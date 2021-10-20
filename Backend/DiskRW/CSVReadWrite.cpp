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
  std::string LineBuffer;
  while (getline(FILE, LineBuffer)) {
    std::vector<std::string> DataOneLine;
    std::stringstream SS(LineBuffer);
    std::string BUFFER;
    while (getline(SS, BUFFER, ',')) {
      DataOneLine.push_back(BUFFER);
    }
    Data->push_back(DataOneLine);
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
