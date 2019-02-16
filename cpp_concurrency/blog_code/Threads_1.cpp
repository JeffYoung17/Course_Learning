#include <iostream>
#include <thread>
using namespace std;

int func()
{
    // do some work
    cout << "hello" << endl;
    return 1;
}

int main(int argc, char** argv)
{
    std::thread t(func);
    t.join(); // if the func return a value, it will be ignored

    return 0;
}