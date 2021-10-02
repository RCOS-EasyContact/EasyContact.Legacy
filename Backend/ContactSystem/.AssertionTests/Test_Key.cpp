// C Standard Library
#include <assert.h>
#include <stdlib.h>
// C++ Standard Library
#include <iostream>
// Testing Header Files
#include "../Key.h"

int main() {
  BCS::Key A("User 1", "Address1@EC.io");
  std::cout << A.Name << A.Address << std::endl;
  exit(EXIT_SUCCESS);
}