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


int main( int argc, char** argv )
{
    int a[4] = {1, 2 ,3, 4};
    reverse( a, 0, 3 );
    for ( int i = 0; i < 4; i++ )
    {
        cout << a[i] << endl;
    }
    return 0;
}