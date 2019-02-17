/*
 * 将数组中指定区间的元素前后颠倒
 * 线性递归，存在多递归基的情况
 * 减而治之：一个平凡的实例+规模变小的问题
 **/
#include <iostream>

using namespace std;

void swap( int& a, int& b )
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void reverse( int* arr, int id_begin, int id_end )
{
    if ( id_begin < id_end )
    {
        swap( arr[id_begin], arr[id_end] );
        reverse( arr, id_begin + 1, id_end - 1 );
    }
    // 如果 id_begin = id_end，意味着刚好交换完全
    // 如果 id_begin > id_end，意味着还剩最后一个，处于中间位置，无需交换
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