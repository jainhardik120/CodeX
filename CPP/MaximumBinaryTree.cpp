#include <bits/stdc++.h>
using namespace std;

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
    TreeNode *constructBinaryTree(vector<int> &nums, int a, int b)
    {
        if (a == b)
        {
            return new TreeNode(nums[a]);
        }
        if (a > b)
        {
            return NULL;
        }
        int max = -1;
        int maxIndex = -1;
        for (int i = a; i <= b; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                maxIndex = i;
            }
        }
        TreeNode *result = new TreeNode(max);
        result->left = constructBinaryTree(nums, a, maxIndex - 1);
        result->right = constructBinaryTree(nums, maxIndex + 1, b);
        return result;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return constructBinaryTree(nums, 0, nums.size() - 1);
    }
};

int main()
{

    return 0;
}