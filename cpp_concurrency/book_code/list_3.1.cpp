#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <algorithm>
using namespace std;

std::list<int> some_list;
std::mutex list_mutex;

void add_to_list( int new_value )
{
    std::lock_guard<std::mutex> guard(list_mutex);
    some_list.push_back( new_value );
    
}

bool list_contains( int value_to_find )
{
    std::lock_guard<std::mutex> guard(list_mutex);
    return std::find( some_list.begin(), some_list.end(), value_to_find ) != some_list.end();
}

void add_porcess()
{
    cout << "enter:" << this_thread::get_id() << endl;
    for( int i = 0; i < 4; i++ )
    {
        add_to_list(i);
    }
    cout << "leave:" << this_thread::get_id() << endl;
}

int main( int argc, char** argv )
{
    std::thread t1(add_porcess);
    t1.join();

    for( auto& ele : some_list )
    {
        cout << ele << endl;
    }

    return 0;
}