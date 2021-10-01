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
#include "../ContactBook.h"
int main() {
  std::string A = "New";
  A.clear();
  std::cout << A.empty() << std::endl;
  exit(EXIT_SUCCESS);
}