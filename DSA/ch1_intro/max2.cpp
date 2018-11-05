/*
 * 求数组指定区间中的两个元素：最大和次大
 **/
#include <iostream>

using namespace std;

void max2_1st( int* _arr, int start, int end, int& index_Max, int& index_Sec );

int main( int argc, char** argv )
{
    int arr[5] = {2, 1, 4, 3, 5};

    // 的确，这种情况退出for循环后，cout的是for外面的ha
    // for里面的ha在退出for以后已经被销毁了
    int ha = 0;
    for ( int i =0, ha=0 ; i<5; i++ )
    {
        cout << arr[i] << endl;
        cout << ha << endl;
    }
    cout << ha << endl;

    int x1, x2 = 0;
    max2_1st( arr, 0, 5, x1, x2);
    cout << arr[x1] << " " << arr[x2] << endl;
    return 0;
}

// index_Max和index_Sec的初始化放到for循环括号内的开头貌似会出错。。。
// 结束for循环的时候index_Max会被清零。。不知道什么鬼
void max2_1st( int* _arr, int start, int end, int& index_Max, int& index_Sec )
{
    index_Max = start;
    for ( int i = start+1; i < end; i++ )
    {
        if ( _arr[index_Max] < _arr[i] )
            index_Max = i;
    }

    index_Sec = start;
    for ( int i = start+1; i<index_Max; i++ )
    {
        
        if( _arr[index_Sec] < _arr[i] )
            index_Sec = i;
    }

    for ( int i = index_Max+1; i<end; i++ )
    {
        if ( _arr[index_Sec] < _arr[i] )
            index_Sec = i;
    }
}