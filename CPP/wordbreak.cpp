#include <bits/stdc++.h>
using namespace std;

struct Node
{
    bool isEnd = false;
    Node *next[26];
};

class Solution
{
    void insertString(string s, Node *&root)
    {
        Node *curr = root;
        for (char ch : s)
        {
            if (!curr->next[ch - 'a'])
            {
                curr->next[ch - 'a'] = new Node();
            }
            curr = curr->next[ch - 'a'];
        }
        curr->isEnd = true;
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        Node *root = new Node();
        for (auto word : wordDict)
        {
            insertString(word, root);
        }
        int len = s.length();
        vector<bool> exist(len + 1, false);
        vector<vector<vector<string>>> words(len + 1);
        exist[len] = true;
        for (int i = len - 1; i >= 0; i--)
        {
            Node *temp = root;
            string curr = "";
            int itr = i;
            while (temp->next[s[itr] - 'a'] && itr < len + 1)
            {
                curr += s[itr];
                temp = temp->next[s[itr] - 'a'];
                if (temp->isEnd && exist[itr + 1])
                {
                    exist[i] = true;
                    if (words[itr + 1].empty())
                    {
                        vector<string> temp;
                        temp.push_back(curr);
                        words[i].push_back(temp);
                    }
                    else
                    {
                        for (auto j : words[itr + 1])
                        {
                            vector<string> temp = j;
                            temp.insert(temp.begin(), curr);
                            words[i].push_back(temp);
                        }
                    }
                }
                itr++;
            }
        }
        vector<string> ans;
        for (auto i : words[0])
        {
            string curr = "";
            for (int j = 0; j < i.size(); j++)
            {
                curr += i[j];
                if (j != i.size() - 1)
                {
                    curr += " ";
                }
            }

            ans.push_back(curr);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
    sol.wordBreak("catsandog", dict);
    return 0;
}