// C++ Standard Library
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
// Standard Template Library
#include <queue>
#include <utility>
#include <vector>

typedef std::string ParamType;
typedef std::function<void(void)> Functor;

void Process(const std::vector<Functor> &Vec){
  for(auto &Op:Vec){
    Op();
  }
}

int main(void){
  std::vector<Functor> Ops;
  std::string Hey="Hey!";
  Ops.push_back([Hey](){
    std::cout<<Hey<<std::endl;
  });
  Hey="Get";
  Ops.push_back([Hey](){
    std::cout<<Hey<<std::endl;
  });
    Hey="Back";
  Ops.push_back([Hey](){
    std::cout<<Hey<<std::endl;
  });
  Process(Ops);
  return 0;
}
