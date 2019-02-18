/*
 * 尾递归及其消除--改成迭代的形式
 * 消除的目的在于 递归会造成过多的空间开销，影响运行的速度
 **/
#include <iostream>
using namespace std;

// 复杂度O(n)
// 但是减少了递归调用所需要的空间和系统实现递归调用所需的时间
// 太尼玛精简了，牛逼
void reverse( int* A, int lo, int hi )
{
    while( lo < hi )
        swap( A[lo++], A[hi--] );
}

// 严格来说，不属于尾递归
int sum_iteration( int* A, int n )
{
    if( n == 0 ) return 0;
    return sum_iteration( A, n - 1 ) + A[n-1];
}

int sum( int* A, int n )
{
    int sum = 0;
    while( 0 < n )
    {
        sum += A[--n];
    }
    return sum;
}

int main( int argc, char** argv )
{
    int a[4] = {1, 2 ,3, 4};
    reverse( a, 0, 3 );
    for ( int i = 0; i < 4; i++ )
    {
        cout << a[i] << endl;
    }
    cout << sum( a, 4 ) << endl;
    cout << sum_iteration( a, 4 ) << endl;
    return 0;
}