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

#include <iostream>
#include <string>

using namespace std;

int main(int argc,char **argv)   {
    auto i=5;
    auto f = [i](int j) {cout<<"capture i="<<i<<", passing i as j="<<j<< endl; };
    while (i<30) {
        i += 10;
        f(i);
    }
}
