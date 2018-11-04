/*
 * 斐波那契数列 
 **/

#include <iostream>

using namespace std;

__int64 fib0( int n );
__int64 fib1( int n );

int main( int argc, char** argv )
{
    // cout << fib0(50) << endl;
    cout << fib1(60) << endl;
    return 0;
}

__int64 fib0( int n )
{
    return ( n<2 ) ? n : fib0(n-1) + fib0(n-2);
}

__int64 fib = 0, temp = 1;
__int64 fib1( int n )
{
    while( n-- > 0 )
    {
        fib = fib + temp;
        temp = fib - temp;
    }
    return fib;
}