#include <iostream>
#include <thread>
using namespace std;

void sayHello()
{
    cout << "hello concurrency!" << endl;
}

int main( int argc, char** argv )
{
    std::thread hello(sayHello);
    hello.join();
    
    return 0;
}