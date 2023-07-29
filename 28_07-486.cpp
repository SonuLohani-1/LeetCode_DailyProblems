#include<bits/stdc++.h>
using namespace std;

// This is the solution of daily challenge of 28th July 2023 in Leetcode
// https://leetcode.com/problems/predict-the-winner/description/

// This is the recursive approach to solve this problem. The idea is to use recursion to find the maximum score that the first player can get. The first player can either choose the first element or the last element. If the first player chooses the first element then the second player can choose either the first element or the last element. If the first player chooses the last element then the second player can choose either the first element or the last element.
// Time complexity: O(2^n)
// Space complexity: O(n)
// there is a great explantion in the editorial of this problem
// https://leetcode.com/problems/predict-the-winner/solution/

class Solution {
public:
    int maxDiff(vector<int> &nums, int left, int right, int n)
    {
        if(left == right)
        {
            return nums[left];
        }

        int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right, n);
        int scoreByRight = nums[right] - maxDiff(nums, left, right -1, n);

        return max(scoreByLeft, scoreByRight);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return maxDiff(nums, 0, n -1, n) >= 0;
    }
};

// This is the top down approach to solve this problem. 
// Time complexity: O(n^2)
// Space complexity: O(n^2)
class Solution {
public:
    int maxDiff(vector<int> &nums, int left, int right, int n, vector<vector<int>> &memo)
    {
        if(left == right)
        {
            return memo[left][right] = nums[left];
        }

        if(memo[left][right] != -1) return memo[left][right];

        int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right, n, memo);
        int scoreByRight = nums[right] - maxDiff(nums, left, right -1, n, memo);

        return memo[left][right] = max(scoreByLeft, scoreByRight);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return maxDiff(nums, 0, n -1, n, memo) >= 0;
    }
};

// This is the bottom up approach to solve this problem.
// Time complexity: O(n^2)
// Space complexity: O(n^2)
// This is the bottom up dp solution
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }

        for (int diff = 1; diff < n; diff++)
        {
            for(int left = 0; left < n - diff; left++)
            {
                int right = left + diff;
                dp[left][right] = max(nums[left] - dp[left + 1][right], nums[right] - dp[left][right - 1]);
            }
        }

        return dp[0][n-1] >= 0;
    }
};

int main()
{
    return 0;
}