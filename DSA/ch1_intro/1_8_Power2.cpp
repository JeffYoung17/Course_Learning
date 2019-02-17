/*
 * 求2的n次幂
 * 线性递归-减而治之：一个平凡的实例+规模变小的问题
 * 采用 不同的 缩减输入规模的 方法
 * 单向递归 和 多向递归
 **/
#include <iostream>
using namespace std;

int square( int num )
{
    return num * num;
}

// 多向递归，但每次只选择一个方向，依然属于线性递归
// 复杂度O(logn)
int power2_multi_direction( int n )
{
    if( n == 0 ) return 1;
    return ( n&1 ) ? square(power2_multi_direction(n >> 1)) << 1 :
                         square(power2_multi_direction(n >> 1));
    // n&1 == 1 意味着n为奇数
}

// 单向递归
// 递归基（平凡的实例） n=0
// 复杂度O(n)
int power2_single_direction( int n )
{
    if( n == 0) return 1;
    return 2 * power2_single_direction( n - 1 );
}

// 暴力迭代
// 复杂度O(n)
int power2_iteration( int n )
{
    int base = 1;
    while( n-- > 0 )
    {
        base *= 2;
    }
    return base;
}

int main( int argc, char** argv )
{
    cout << power2_iteration(4) << endl;
    cout << power2_single_direction(4) << endl;
    cout << power2_multi_direction(4) << endl;
    return 0;
}