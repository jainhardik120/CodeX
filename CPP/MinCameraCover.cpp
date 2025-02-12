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
    unordered_map<TreeNode *, vector<int>> umap;
    int minCoverHelper(TreeNode *root, bool rootFilled, bool rootRequired)
    {
        if (!root)
        {
            return 0;
        }
        unordered_map<TreeNode *, vector<int>>::iterator foundVector = umap.find(root);
        vector<int> solutionVector;
        int reqVal = (rootFilled * 2) + rootRequired;
        if (foundVector != umap.end())
        {
            solutionVector = foundVector->second;
            if (solutionVector[reqVal] != -2)
            {
                return solutionVector[reqVal];
            }
        }
        else
        {
            solutionVector = vector<int>(4, -2);
        }
        cout << root->val << " " << rootFilled << " " << rootRequired << "\n";
        if (rootFilled)
        {
            int left0 = minCoverHelper(root->left, true, false);
            int left1 = minCoverHelper(root->left, false, false);
            int right0 = minCoverHelper(root->right, true, false);
            int right1 = minCoverHelper(root->right, false, false);
            int minAns = 1 + min(left0, left1) + min(right0, right1);
            solutionVector[reqVal] = minAns;
            umap[root] = solutionVector;
            return minAns;
        }
        else
        {
            if (rootRequired)
            {
                if (!(root->left) && !(root->right))
                {
                    solutionVector[reqVal] = -1;
                    umap[root] = solutionVector;
                    return -1;
                }
                if (!(root->left))
                {
                    int minAns = minCoverHelper(root->right, true, true);
                    solutionVector[reqVal] = minAns;
                    umap[root] = solutionVector;
                    return minAns;
                }
                if (!(root->right))
                {
                    int minAns = minCoverHelper(root->left, true, true);
                    solutionVector[reqVal] = minAns;
                    umap[root] = solutionVector;
                    return minAns;
                }
                int left0 = minCoverHelper(root->left, true, true);
                int left1 = minCoverHelper(root->left, false, true);
                int right0 = minCoverHelper(root->right, true, true);
                int right1 = minCoverHelper(root->right, false, true);
                // cout << root->val << " " << left0 << " " << left1 << " " << right0 << " " << right1 << "\n";
                int minAns = left0 + right0;
                if (left1 != -1)
                {
                    minAns = min(minAns, (left1 + right0));
                }
                if (right1 != -1)
                {
                    minAns = min(minAns, (left0 + right1));
                }
                // cout << minAns;
                solutionVector[reqVal] = minAns;
                umap[root] = solutionVector;
                return minAns;
            }
            else
            {
                int left0 = minCoverHelper(root->left, true, true);
                int left1 = minCoverHelper(root->left, false, true);
                int right0 = minCoverHelper(root->right, true, true);
                int right1 = minCoverHelper(root->right, false, true);
                int left;
                int right;
                if (left1 == -1)
                {
                    left = left0;
                }
                else
                {
                    left = min(left0, left1);
                }
                if (right1 == -1)
                {
                    right = right0;
                }
                else
                {
                    right = min(right0, right1);
                }
                int minAns = left + right;
                solutionVector[reqVal] = minAns;
                umap[root] = solutionVector;
                return minAns;
            }
        }
    }

public:
    int minCameraCover(TreeNode *root)
    {
        umap.clear();
        int ans0 = minCoverHelper(root, true, true);
        int ans1 = minCoverHelper(root, false, true);
        if (ans1 == -1)
        {
            return ans0;
        }
        else
        {
            return min(ans0, ans1);
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    cout << sol.minCameraCover(root);
    return 0;
}