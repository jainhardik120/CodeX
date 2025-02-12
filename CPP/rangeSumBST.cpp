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
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if(!root){
            return 0;
        }
        int rootVal = root->val;
        int sum = 0;
        if(rootVal>=low && rootVal<=high){
            sum+=rootVal;
        }
        if(rootVal>low){
        sum+=rangeSumBST(root->left, low, high);

        }
        if(rootVal<high){
        sum+=rangeSumBST(root->right, low, high);

        }
        return sum;
    }
};

int main()
{

    return 0;
}