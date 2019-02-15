#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int new_len = 0;
        int len = nums.size();
        int i = 0;
        for( int j = 0; j < len; j++ )
        {
            if( nums[j] != val )
            {
                nums[i] = nums[j];
                i++;
            }
        }
        new_len = i++;
        return new_len;
    }
};

int main( int argc, char** argv )
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(5);
    Solution solution;
    cout << solution.removeElement(arr, 2) << endl;
    return 0;
}