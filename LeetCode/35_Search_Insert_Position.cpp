#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(target <= nums[i])
            {
                index = i;
                break;
            }
            if(i == nums.size() - 1 && nums[i] < target) return nums.size();
        }
        return index;
    }
};

int main( int argc, char** argv )
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    
    Solution solution;
    cout << solution.searchInsert(arr, 6) << endl;
    return 0;
}