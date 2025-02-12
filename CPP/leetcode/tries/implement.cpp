#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Node
    {
        bool isEnd;
        Node *child[26];
    };
    Node *trie;

    void assignChildNull(Node *trie)
    {
        for (int i = 0; i < 26; i++)
        {
            trie->child[i] = nullptr;
        }
    }

public:
    Trie()
    {
        trie = new Node();
        trie->isEnd = true;
        assignChildNull(trie);
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
                temp->child[index]->isEnd = false;
                assignChildNull(temp->child[index]);
            }
            temp = temp->child[index];
        }
        temp->isEnd = true;
    }

    bool search(string word)
    {
        int n = word.size();
        Node *temp = trie;
        for (int i = 0; i < n; i++)
        {
            int index = word[i] - 'a';
            if (!temp->child[index])
            {
                return false;
            }
            temp = temp->child[index];
        }
        return (temp->isEnd);
    }

    bool startsWith(string prefix)
    {
        int n = prefix.size();
        Node *temp = trie;
        for (int i = 0; i < n; i++)
        {
            int index = prefix[i] - 'a';
            if (!temp->child[index])
            {
                return false;
            }
            temp = temp->child[index];
        }
        return true;
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << endl << trie->search("apple");   // return True
    cout << endl << trie->search("app");     // return False
    cout << endl << trie->startsWith("app"); // return True
    trie->insert("app");
    cout << endl << trie->search("app"); // return True
    return 0;
}