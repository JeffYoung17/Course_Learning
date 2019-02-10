#include <iostream>
using namespace std;

int countOnes_A(unsigned int num)
{
    int count = 0;
    while( 0 < num )
    {
        count += (1 & num);
        num = num >> 1;
    }
    return count;
}

int main(int argc, char** argv)
{
    cout << countOnes_A(441) << endl;

    return 0;
}