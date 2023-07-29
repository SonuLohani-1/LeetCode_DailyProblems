#ifndef MYCLASSES_H
#define MYCLASSES_H

#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const std::vector<int> &nums)
{
    if (nums.empty())
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(nums[0]);
    std::queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size())
    {
        TreeNode *node = q.front();
        q.pop();

        if (nums[i] != NULL)
        {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;

        if (i < nums.size() && nums[i] != NULL)
        {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// Other classes or definitions go here

#endif
