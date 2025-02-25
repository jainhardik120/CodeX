#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (!original)
        {
            return NULL;
        }

        if (original == target)
        {
            return cloned;
        }
        else
        {
            TreeNode *left = getTargetCopy(original->left, cloned->left, target);
            TreeNode *right = getTargetCopy(original->right, cloned->right, target);
            if (left)
            {
                return left;
            }
            if (right)
            {
                return right;
            }
            return NULL;
        }
    }
};

int main()
{

    return 0;
}