#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};


/*
             14
            14     3
           N 8    8 12
            N 6 17 3 N 1
           11 10 N 6 6 13  N 10
           17 7 N 11 7


*/
class Solution
{
    vector<int> sol;

    void constructBottomView(Node* root){
        if(!root->left && !root->right){
            sol.push_back(root->data);
        }
        if(root->left){
            constructBottomView(root->left);
        }
        if(root->right){
            constructBottomView(root->right);
        }
    }


public:
    vector<int> bottomView(Node *root)
    {

    }
};

int main()
{

    return 0;
}