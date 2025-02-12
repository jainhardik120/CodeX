#include <bits/stdc++.h>
using namespace std;

bool compareStringLogs(string s1, string s2)
{
    int l1 = -1, l2 = -1;
    int itr = 0;
    while (itr < s1.length())
    {
        if (s1[itr] == ' ')
        {
            l1 = itr;
            break;
        }
        itr++;
    }
    itr = 0;
    while (itr < s2.length())
    {
        if (s2[itr] == ' ')
        {
            l2 = itr;
            break;
        }
        itr++;
    }
    int compareLog = s1.compare(l1 + 1, s1.length() - (l1 + 1), s2, l2 + 1, s2.length() - (l2 + 1));
    if (compareLog == 0)
    {
        int compareIdentifier = s1.compare(0, l1, s2, 0, l2);
        return (compareIdentifier < 0);
    }
    else
    {
        return (compareLog < 0);
    }
}

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> ans;
        vector<string> digitLogs;
        for (int i = 0; i < logs.size(); i++)
        {

            char lastCharacter = logs[i][(logs[i].size() - 1)];
            if (lastCharacter >= '0' && lastCharacter <= '9')
            {
                digitLogs.push_back(logs[i]);
            }
            else
            {
                ans.push_back(logs[i]);
            }
        }
        sort(ans.begin(), ans.end(), compareStringLogs);
        for (int i = 0; i < digitLogs.size(); i++)
        {
            ans.push_back(digitLogs[i]);
        }
        digitLogs.clear();
        return ans;
    }
};

int main()
{

    return 0;
}