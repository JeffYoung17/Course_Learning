#include <iostream>
#include <vector>
using namespace std;

// 思路最简单的方法
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        bool isCarry = false;
        int len = digits.size();
        int cur_bit = 0;
        vector<int> result;
        
        cur_bit = 1 + digits[len-1];
        result.insert( result.begin(), cur_bit % 10 );
        if( cur_bit >= 10 )
            isCarry = true;
        else
            isCarry = false;
        
        for( int i = len -2; i >= 0; i-- )
        {
            if( isCarry == true )
            {
                cur_bit = digits[i] + 1;
                result.insert( result.begin(), cur_bit % 10 );
                if( cur_bit >= 10 )
                    isCarry = true;
                else
                    isCarry = false;
            }
            else
            {
                cur_bit = digits[i];
                result.insert( result.begin(), cur_bit % 10 );
                isCarry = false;
            }
        }

        if( isCarry == true )
        result.insert( result.begin(), 1 );
        return result;
    }
};

int main( int argc, char** argv)
{
    

    return 0;
}