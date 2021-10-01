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
// ContactSystem Header Files
#include "../Contact.h"
int main() {
  BCS::Contact A("Name 1", "Address1@EasyContact.io",
                 std::set<uint8_t>{1, 2, 3, 4, 5});
  std::cout << A << std::endl;
  exit(EXIT_SUCCESS);
}