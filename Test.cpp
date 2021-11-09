// C++ Standard Library
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
// Standard Template Library
#include <queue>
#include <vector>

typedef std::function<std::vector<std::string>(void)> Functor;

void Execute(std::vector<std::string> &Vec, Functor Operation) { Operation(); }

int main(void) {
  std::string Str = "No Change";
  auto Lambda = [Str]() mutable {
    Str = "Changed!";
    std::cout << "Inside: " << Str << std::endl;
  };
  Lambda();
  std::cout << "=== END PUSH ===\n";
  std::cout << Str << std::endl;
  return 0;
}

#if 0
typedef std::function<void(std::vector<std::string>)> Functor;

void Execute(std::vector<std::string> &Vec,Functor Operation){
  Operation(Vec);
}

int main(void){
  std::vector<std::string> Vec;
  Execute(Vec,[](std::vector<std::string> Vec)mutable{
    Vec.push_back("01");
  });
  std::cout<<"=== END PUSH ===\n";
  for(const std::string &i:Vec){
    std::cout<<i<<std::endl;
  }
  return 0;
}
#endif