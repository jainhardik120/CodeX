#include <bits/stdc++.h>
using namespace std;

class MapSum {
    struct Node{
        bool isWord;
        int value;
        Node* child[26];

        Node(){
            isWord = false;
            value = 0;
            for (int i = 0; i < 26; i++)
            {
                child[i] = nullptr;
            }
        }
    };
    Node* map;

    int childSum(Node* root){
        int sum = 0;
        if(!root){
            return sum;
        }
        if(root->isWord){
            sum +=root->value;
        }
        for (int i = 0; i < 26; i++)
        {
            sum += childSum(root->child[i]);
        }
        return sum;
    }

public:
    MapSum() {
        map = new Node();
        map->isWord = true;
    }
    
    void insert(string key, int val) {
        int n = key.size();
        Node *temp = map;
        for (int i = 0; i < n; i++)
        {
            int index = key[i] - 'a';
            if (!temp->child[index])
            {
                temp->child[index] = new Node();
            }
            temp = temp->child[index];
        }
        temp->isWord = true;
        temp->value = val;
    }
    
    int sum(string prefix) {
        int n = prefix.size();
        Node *temp = map;
        for (int i = 0; i < n; i++)
        {
            int index = prefix[i] - 'a';
            if (!temp->child[index])
            {
                return 0;
            }
            temp = temp->child[index];
        }
        return childSum(temp);
    }
};

int main()
{
    MapSum* map = new MapSum();
    map->insert("apple", 3);
    cout << map->sum("ap") << endl;
    map->insert("app", 2);
    cout << map->sum("ap") << endl;
    return 0;
}