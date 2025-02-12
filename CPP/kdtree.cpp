#include<bits/stdc++.h>
using namespace std;

struct node{
    int* data;
    int dimension;
    node* left;
    node* right;

    node(int *data, int dimension){
        int n = sizeof(data)/sizeof(data[0]);
        this->data = new int[n];
        for(int i=0; i < n; i++){
            this->data[i] = data[i];
        }
        this->dimension = dimension;
        this->left=nullptr;
        this->right=nullptr;
    }
};

void insert(node* &root, int *data){
    node* parent = root;
    int n = sizeof(data)/sizeof(data[0]);
    node* newnode= new node(data, ((root)?(root->dimension+1):0)%n);
    if(!root){
        root =  newnode;
        return;
    }
    bool dim = false;
    while(1){
        if(data[parent->dimension]>parent->data[parent->dimension]){
             dim = true;
            if(parent->right){
                parent = parent->right;
               
            }else{
                break;
            }
        }else{
            dim = false;
            if(parent->left){
                parent = parent->left;
                
            }else{
                break;
            }
        }
    }
    
    if(dim){
        parent->right = newnode;
    }else{
        parent->left = newnode;
    }
}

int main(){
    int m = 6, n = 2;
 
    int** a = new int*[m];
 
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }
    a[0][0] = 51;
    a[0][1] = 60;
    a[1][0] = 30;
    a[1][1] = 90;
    a[2][0] = 70;
    a[2][1] = 80;
    a[3][0] = 40;
    a[3][1] = 30;
    a[4][0] = 55;
    a[4][1] = 38;
    a[5][0] = 38;
    a[5][1] = 47;
    node *root = nullptr;
    for (int i = 0; i < m; i++) {
        insert(root, a[i]);
    }

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        cout  << top->data[0] << " " << top->data[1] << "\n";
        if(top->left) {q.push(top->left);}
        if(top->right) {q.push(top->right);}
    }


    for(int i=  0; i < 6; i++){
        int minDist = INT_MAX;
        int index = -1;
        for(int j = 0; j < 6; j++){
            if(i==j){
                continue;
            }
            int newDist = (abs(a[i][0]-a[j][0])*abs(a[i][0]-a[j][0])) + (abs(a[i][1]-a[j][1])*abs(a[i][1]-a[j][1]));
            if(newDist<minDist){
                minDist = newDist;
                index = j;
            }
        }
        cout << index << " ";
    }
    return 0;
}