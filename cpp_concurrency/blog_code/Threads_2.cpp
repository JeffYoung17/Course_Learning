#include <iostream>
#include <thread>
#include <string>
#include <cstring>
using namespace std;

void func(int i, double d, const std::string& s) // 因为对于s是常引用，所以启动线程的时候std::ref("hello")可有可无
{
    cout << i << " " << d << " " << s << endl;
}

int main(int argc, char** argv)
{
    std::thread t(func, 1, 3.14, "hello");
    t.join();
    return 0;
}