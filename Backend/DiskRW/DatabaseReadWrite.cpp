/**
 * RCOS-EasyContact
 * EasyContact/Backend/DiskRW
 * DatabaseReadWrite.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_DISKRW_DATABASEREADWRITE_CPP_
#define BACKEND_DISKRW_DATABASEREADWRITE_CPP_
#include "DatabaseReadWrite.hpp"
void DRW::Read_UserContacts(GlobalMutex<BCS::Books>* ContactBook) {
  std::vector<std::vector<std::string>> Data;
  LoadFromDisk("DATABASE/UserContacts.csv", &DATA);
  {  // Critical Section
    ContactBook.Lock();
    for (std::vector<std::vector<std::string>>::const_iterator A = Data.begin();
         A != Data.end(); ++A) {
      if (A->size() != 2) {
        std::cerr << "--> Run-time Error: " << std::endl
                  << "Read_UserContacts:"
                  << "Data Corrupted" << std::endl;
        exit(EXIT_FAILURE);
      }
      if (ContactBook->newContact(BCS::Key(A->front(), A->back())) == false) {
        std::cerr << "--> Run-time Warning: " << std::endl
                  << "Read_UserContacts:"
                  << "Contact Already Exist" << std::endl;
      }
    }
    ContactBook.Unlock();
  }  // End Critical Section
}
void DRW::Write_UserContacts(const GlobalMutex<BCS::Books>& ContactBook) {
  {  // Critical Section
    ContactBook.Lock();
    std::vector<std::vector<std::string>> Data;
    for (std::unordered_set<BCS::Key>::const_iterator i = ContactBook->begin();
         i != ContactBook->end(); ++i) {
      Data.push_back(i->Name, i->Email);
    }
    ContactBook.Unlock();
  }  // End Critical Section
  SaveToDisk("DATABASE/UserContacts.csv", DATA);
}
#endif  // BACKEND_DISKRW_DATABASEREADWRITE_CPP_