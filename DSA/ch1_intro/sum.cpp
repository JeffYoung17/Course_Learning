/*
 * 数组求和
 * (1)遍历数组
 * (2)减而治之
 * (3)分而治之
 **/
#include <iostream>

using namespace std;

int sum_normal( int* a , int n );
int sum_decrease( int* a, int n );
int sum_divide( int* a, int start, int end );

int main( int argc, char** argv )
{
    int arr[5] = {1, 4, 5, 6, 9};
    cout << sum_normal( arr, 5 ) << endl;
    cout << sum_decrease( arr, 5 ) << endl;
    cout << sum_divide( arr, 0, 4 );
    return 0;
}

int sum_normal( int* a , int n )
{
    int result = 0; // O(1)
    for ( int i = 0; i < n; i++ )
    {
        result += a[i]; // n*O(1) = O(n)
    }
    return result; // O(1)
}

int sum_decrease( int* a, int n )
{
    return ( n<1 ) ? 0 : sum_decrease( a, n-1 ) + a[n-1] ;
}

int sum_divide( int* a, int start, int end )
{
    if ( start == end) return a[start];

    int mid = ( start + end ) / 2;
    return sum_divide( a, start, mid ) + sum_divide( a, mid+1, end );
}