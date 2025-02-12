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

/*
     5
   4   6
  N N 3 7

*/

class Solution
{

    bool isBST(TreeNode *root, int begin, int end)
    {
        if (!root)
        {
            return true;
        }
        if (!(root->val >= begin && root->val <= end))
        {
            return false;
        }
        bool left = true;
        bool right = true;
        if (root->left)
        {
            if (root->val == INT_MIN)
            {
                left = false;
            }
            else
            {
                left = isBST(root->left, begin, root->val - 1);
            }
        }
        if (root->right)
        {
            if (root->val == INT_MAX)
            {
                right = false;
            }
            else
            {
                right = isBST(root->right, root->val + 1, end);
            }
        }
        return (left && right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isBST(root, INT_MIN, INT_MAX);
    }
};

// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if(!root){
//             TreeNode* newNode = new TreeNode(val);
//             return newNode;
//         }
//         if(val>root->val){
//             TreeNode* right=insertIntoBST(root->right, val);
//             root->right = right;
//         }else{
//             TreeNode* left = insertIntoBST(root->left, val);
//             root->left = left;
//         }
//         return root;
//     }
// };

// class Solution {

// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root){
//             return NULL;
//         }
//         if(root==p || root==q){
//             return root;
//         }
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
//         if(!left && !right){
//             return NULL;
//         }
//         if(left && !right){
//             return left;
//         }
//         if(!left && right){
//             return right;
//         }
//         return root;
//     }
// };

// class Solution {
//     int diameter;
//     int maxDepth(TreeNode* root) {
//         if(!root){
//             return 0;
//         }
//         int left = maxDepth(root->left);
//         int right = maxDepth(root->right);
//         int currDiameter = left + right;
//         if(currDiameter>diameter){
//             diameter = currDiameter;
//         }
//         return 1 + max(left, right);
//     }
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         diameter=0;
//         maxDepth(root);
//         return diameter;
//     }
// };

// class Solution {

// public:
//     int maxDepth(TreeNode* root) {
//         if(!root){
//             return 0;
//         }
//         int left = maxDepth(root->left);
//         int right = maxDepth(root->right);
//         return 1 + max(left, right);
//     }
// };

// class BSTIterator {
//     vector<int> bst;
//     int pos;
//     void construct(TreeNode* root){
//         if(!root){
//             return;
//         }
//         construct(root->left);
//         bst.push_back(root->val);
//         construct(root->right);
//     }
// public:
//     BSTIterator(TreeNode* root) {
//         construct(root);
//         pos = -1;
//     }

//     int next() {
//         return bst[++pos];
//     }

//     bool hasNext() {
//         return ((pos+1)<bst.size());
//     }
// };

// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(!root){
//             return NULL;
//         }
//         TreeNode* left = invertTree(root->left);
//         TreeNode* right = invertTree(root->right);
//         root->left = right;
//         root->right = left;
//         return root;
//     }
// };

// class Solution {

//     int calcSumDiff(TreeNode* root){
//         if(!root){
//             return 0;
//         }
//         int leftSum = calcSumDiff(root->left);
//         int rightSum = calcSumDiff(root->right);
//         int sum = leftSum+rightSum+root->val;
//         int diff = leftSum-rightSum;
//         if(diff<0){
//             diff*=-1;
//         }
//         root->val = diff;
//         return sum;
//     }

//     int calcSum(TreeNode* root){
//         if(!root){
//             return 0;
//         }
//         int leftSum = calcSum(root->left);
//         int rightSum = calcSum(root->right);
//         return (root->val + leftSum + rightSum);
//     }

// public:
//     int findTilt(TreeNode* root) {
//         calcSumDiff(root);
//         return calcSum(root);
//     }
// };

// class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//         int sum = 0;
//         if(!root){
//             return 0;
//         }
//         if(root->left && (!root->left->left) && (!root->left->right)){
//             sum += root->left->val;
//         }
//         int left = sumOfLeftLeaves(root->left);
//         int right = sumOfLeftLeaves(root->right);
//         return (sum+left+right);
//     }
// };

// class Solution {

//     vector<TreeNode*> getBaseNodes(vector<TreeNode*>&parentNodes){
//         vector<TreeNode*> ans;
//         for(auto itr = parentNodes.begin(); itr != parentNodes.end(); itr++){
//             if((*itr)->left){
//                 ans.push_back((*itr)->left);
//             }
//             if((*itr)->right){
//                 ans.push_back((*itr)->right);
//             }
//         }
//         if(ans.size()==0){
//             return parentNodes;
//         }
//         return getBaseNodes(ans);
//     }

// public:
//     int deepestLeavesSum(TreeNode* root) {
//         vector<TreeNode*> parent;
//         parent.push_back(root);
//         vector<TreeNode*> leafNodes= getBaseNodes(parent);
//         int sum = 0;
//         for(auto itr = leafNodes.begin(); itr != leafNodes.end(); itr++){
//             if(*itr){
//                 sum += (*itr)->val;
//             }
//         }
//         return sum;
//     }
// };

int main()
{

    return 0;
}