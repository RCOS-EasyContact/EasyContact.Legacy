/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem/.AssertionTests
 * TestContact.cpp
 * Copyright [2021] <RCOS-EasyContact>
 */
// C Standard Library
#include <assert.h>
#include <stdlib.h>
// C++ Standard Library
#include <iostream>
#include <sstream>
#include <string>
// ContactSystem Header Files
#include "../Contact.h"
int main() {
  BCS::Contact A("Name 1", "Address1@EasyContact.io",
                 std::set<uint8_t>{1, 2, 3, 4, 5});
  {
    std::stringstream Buffer;
    std::string Expected =
        "\"Name 1\",\"Address1@EasyContact.io\",\"1:2:3:4:5\"";
    Buffer << A;
    assert(Buffer.str() == Expected);
  }
  {
    BCS::Contact B;
    B = A;
    std::stringstream Buffer;
    std::string Expected =
        "\"Name 1\",\"Address1@EasyContact.io\",\"1:2:3:4:5\"";
    Buffer << B;
    assert(Buffer.str() == Expected);
  }

  std::cout << "All Tests Passed" << std::endl;
  exit(EXIT_SUCCESS);
}