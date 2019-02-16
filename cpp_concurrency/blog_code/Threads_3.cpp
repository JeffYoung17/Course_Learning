#include <iostream>
#include <thread>
using namespace std;

void func(int& a)
{
    a++;
    cout << "in the thread function: " << a << endl;
}

int main(int argc, char** argv)
{
    int num = 3;
    std::thread t(func, std::ref(num)); // 默认是值传递，如果传引用，需要加上std::ref()
    t.join();
    cout << "in the init thread of main function: " << num << endl; 

    return 0;
}