#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int max_len = 0;
    int count = 0;
    void count_subsequence(vector<int>& nums, int i, int last, int curr_len)
    {
        if(i == nums.size())
        {
            if(curr_len == max_len)
            {
                count++;
            }
            else if(curr_len > max_len)
            {
                max_len = curr_len;
                count = 1;
            }
            return;
        }
        if(nums[i] > last) // we have option to take this number
        {
            count_subsequence(nums, i+1, nums[i], curr_len+1);
        }

        count_subsequence(nums, i+1, last, curr_len);
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        count_subsequence(nums, 0, int(-1e9), 0);
        return count;
    }
};
int main()
{
    vector<int> nums = {2, 2, 2, 2, 2};
    Solution obj;
    cout<<obj.findNumberOfLIS(nums) << endl;
    return 0;
}