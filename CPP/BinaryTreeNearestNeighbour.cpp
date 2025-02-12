// C++ Code to insert node and to print inorder traversal
// using iteration

#include <bits/stdc++.h>
using namespace std;
int count = 0;
// BST Node
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int val)
		: val(val)
		, left(NULL)
		, right(NULL)
	{
	}
};

void insert(Node*& root, int key)
{
	Node* node = new Node(key);
	if (!root) {
		root = node;
		return;
	}
	Node* prev = NULL;
	Node* temp = root;
	while (temp) {
		if (temp->val > key) {
			prev = temp;
			temp = temp->left;
		}
		else {
			prev = temp;
			temp = temp->right;
		}
	}
	if (prev->val > key)
		prev->left = node;
	else
		prev->right = node;
}

// Utility function to print inorder traversal
void inorder(Node* root)
{
	Node* temp = root;
	stack<Node*> st;
	while (temp != NULL || !st.empty()) {
		if (temp != NULL) {
			st.push(temp);
			temp = temp->left;
		}
		else {
			temp = st.top();
			st.pop();
			cout << temp->val << " ";
			temp = temp->right;
		}
	}
}

int nearestNeighbour(Node* root){

    if(!root->left && !root->right){
        return INT_MAX;
    }
    int ans = INT_MAX;
    if(root->left){
        Node* temp = root->left;
        while(temp->right){
            temp = temp->right;
        }
        ans = min(ans, abs(root->val - temp->val));
        ans = min(ans, nearestNeighbour(root->left));
    }
    if(root->right){
        Node* temp = root->right;
        while(temp->left){
            temp = temp->left;
        }
        ans = min(ans, abs(root->val - temp->val));
        ans = min(ans, nearestNeighbour(root->right));
    }
    return ans;
}

// Driver code
int main()
{
	Node* root = NULL;
	insert(root, 50);
	insert(root, 30);
	insert(root, 70);
	insert(root, 10);
	insert(root, 40);
	insert(root, 35);
	insert(root, 42);
	insert(root, 60);

    cout << nearestNeighbour(root);
	return 0;
}
