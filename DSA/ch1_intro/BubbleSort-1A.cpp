#include <iostream>
using namespace std;

void bubblesort(int A[], int n)
{
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i = 1; i < n; i++)
        {
            if(A[i-1] > A[i])
            {
                swap(A[i-1], A[i]);
                sorted = false;
            }
        }
        n--;
    }
}

int main(int argc, char** argv)
{
    int arr[] = {1, 0, 4, 3};
    bubblesort(arr, 4);
    for(int i = 0; i < 4; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}