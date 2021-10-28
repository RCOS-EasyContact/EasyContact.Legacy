/**
 * RCOS-EasyContact
 * EasyContact/Backend/Contacts
 * ContactReadWrite.hpp
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_DISKRW_CONTACTREADWRITE_HPP_
#define BACKEND_DISKRW_CONTACTREADWRITE_HPP_
// C++ Standard Library
#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>
// Standard Template Library
#include <memory>
#include <vector>
// SQL Lite Library
#include <SQLiteCpp.h>
#include <VariadicBind.h>
namespace BCS{
  class Contacts{
    public:
    const std::string RCSID;
    explicit Contacts(const std::string& newRCSID): RCSID(newRCSID){
       if(!std::filesystem::directory_entry("UserData/"+RCSID).is_directory()){
       std::filesystem::create_directory("UserData/"+RCSID);
       copy_file( std::filesystem::directory_entry("UserData/.DEFAULT/Contacts.db3"),
                std::filesystem::directory_entry("UserData/"+RCSID+"/Contacts.db3"));
       }
    }

  };
}
#endif // BACKEND_DISKRW_CONTACTREADWRITE_HPP_