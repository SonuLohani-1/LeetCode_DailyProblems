#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem All possible full binary trees on leeetcode
// https://leetcode.com/problems/all-possible-full-binary-trees/

// The intution behind this problem is that we can use recursion to solve this problem

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    // hashmap to store the root of each possible combinations  of binary tree roots
    unordered_map<int, vector<TreeNode *>> memo;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        // if n is even we can form any binary trees
        if (n % 2 == 0)
            return {};

        // Base Case
        if (n == 1)
            return {new TreeNode(0)};

        // if memo already already contains the the number n then return that elements
        if (memo.find(n) != memo.end())
        {
            return memo[n];
        }

        vector<TreeNode *> res;
        for (int i = 1; i < n - 1; i += 2)
        {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - i - 1);

            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(0, l, r);
                    res.push_back(root);
                }
            }
        }

        return memo[n] = res;
    }
};

/*
This is the description of the above solution:
first there should be odd number of nodes there to have a solution.
then we can divide the nodes into two parts, left and right.
left part can have 1,3,5,7... nodes, right part will have the rest.
then we can recursively solve the problem.

We also observe that there are overlapping subproblems in this problem.
therefore we store the result of each subproblem in a hashmap and return the result if the subproblem is already solved.
*/


// This is the bottom up approach of the above problem here also we are doing the same thing but in a bottom up manner
class Solution2
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
        {
            return {};
        }

        vector<vector<TreeNode *>> dp(n + 1);

        dp[1].push_back(new TreeNode(0));

        for (int count = 3; count <= n; count += 2)
        {
            for (int i = 1; i < count - 1; i += 2)
            {
                int j = count - 1 - i;
                for (auto left : dp[i])
                {
                    for (auto right : dp[j])
                    {
                        TreeNode *root = new TreeNode(0, left, right);
                        dp[count].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
};
int main()
{
    return 0;
}