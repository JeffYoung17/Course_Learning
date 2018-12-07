#include <iostream>
#include <vector>

using namespace std;

// 最傻暴力方法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for ( int i = 0; i < nums.size() - 1; i++ ) {
            for ( int j = i+1; j < nums.size(); j++ ) {
                if( nums[i] + nums[j] == target ) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                    }
            }
        }
    }
};



int main ( int argc, char** argv )
{
    vector<int> demo;
    vector<int> test = {2, 7, 11, 15};
    int target = 22;
    Solution s_obj;
    demo = s_obj.twoSum( test, target );
    cout << demo[0] << " " << demo[1] << endl;
    return 0;
}