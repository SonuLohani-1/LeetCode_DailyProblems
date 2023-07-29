// In an array all the numbers are present thrice except one which is present one we have to find the number in linear time and constant space

// I am thinking that we can count the bits at each place the keep their count and if count at position is multiple of three we drop that bit;
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int numFromBits(vector<int> bits)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans += bits[i] % 3 * pow(2, i);
        }
        return ans;
    }

public:
    int singleNumber(vector<int> &nums) 
    {
        vector<int> bits(32, 0); // assuming 32 bits number
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            for (int j = 0; j < 32; j++)
            {
                bits[j] += (num >> j) & 1;
            }
        }
        return numFromBits(bits);
    }
};
int main()
{
    vector<int> arr = {0, 1, 0, 1, 0, 1, 99};
    Solution solution;
    int ans = solution.singleNumber(arr);
    cout << ans << endl;
    return 0;
}