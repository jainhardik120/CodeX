#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Node
    {
        bool isEnd;
        Node *child[26];
        vector<string> prefixOf;

        Node()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
            {
                child[i] = nullptr;
            }
            prefixOf = vector<string>();
        }
    };
    Node *trie;

public:
    Trie()
    {
        trie = new Node();
        trie->isEnd = true;
    }

    void insert(string word)
    {
        int n = word.size();
        Node *temp = trie;
        for (int i = 0; i < n; i++)
        {
            int index = word[i] - 'a';
            if (!temp->child[index])
            {
                temp->child[index] = new Node();
            }
            temp = temp->child[index];
        }
        temp->isEnd = true;
    }
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        Trie* trie = new Trie();
        for(auto itr : products){
            trie->insert(itr);
        }
    }
};

int main()
{

    return 0;
}