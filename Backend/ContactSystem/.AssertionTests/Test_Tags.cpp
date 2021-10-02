// C Standard Library
#include <assert.h>
#include <stdlib.h>
// C++ Standard Library
#include <iostream>
// Testing Header Files
#include "../Tags.h"

int main() {
  BCS::Tags A;
  A.newTag("Profs");
  A.newTag("Friends");
  {
    auto R = A.getAllTags();
    for (auto i : R) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  A.newTag("Friends");
  {
    auto R = A.getAllTags();
    for (auto i : R) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  A.newTag("Temp");
  A.removeTag("Temp");
  {
    auto R = A.getAllTags();
    for (auto i : R) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  A.assignTagTo("Friends", "PersonA");
  A.assignTagTo("Profs", "PersonA");
  {
    auto R = A.getNameInTags("PersonA");
    for (auto i : R) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  A.removeTag("Profs");
  {
    auto R = A.getNameInTags("PersonA");
    for (auto i : R) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  A.assignTagTo("Friends", "PersonB");
  A.assignTagTo("Friends", "PersonC");
  A.assignTagTo("Friends", "PersonD");
  {
    auto R = A.getTagContains("Friends");
    for (auto i : R) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  exit(EXIT_SUCCESS);
}