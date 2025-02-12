#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int numOfStrings = strs.size();
        vector<vector<int>> numOfChars = vector<vector<int>>(numOfStrings, vector<int>(26, 0));
        for (int i = 0; i < numOfStrings; i++)
        {
            for (int j = 0; j < strs[i].size(); j++)
            {
                int ch = strs[i][j] - 'a';
                numOfChars[i][ch]++;
            }
        }
    }
};

int main()
{

    return 0;
}