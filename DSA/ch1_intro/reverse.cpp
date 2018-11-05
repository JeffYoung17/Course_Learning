/*
 * 将数组中指定区间的元素前后颠倒
 * 递归的方法
 * 减而治之：一个平凡的实例+规模变小的问题
 **/
#include <iostream>

using namespace std;

void reverse( int* arr, int id_begin, int id_end );

int main( int argc, char** argv )
{
    int a[3] = {1, 2 ,3};
    reverse( a, 0, 2 );
    for ( int i=0; i<3; i++ )
    {
        cout << a[i] << endl;
    }

    return 0;
}

void reverse( int* arr, int id_begin, int id_end )
{
    if ( id_begin < id_end )
    {
        swap( arr[id_begin], arr[id_end] );
        reverse( arr, id_begin+1, id_end-1 );
    }
}

void swap( int& a, int& b )
{
    int temp = 0;
    temp = a;
    b = a;
    a = temp;
}