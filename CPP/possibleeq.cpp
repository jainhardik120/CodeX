#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> makeLengths(vector<int> &original)
    {
        vector<int> sol;
        if (original.size() == 1)
        {
            sol.push_back(original[0]);
        }
        else if (original.size() == 2)
        {
            if (original[1] != 0)
            {
                sol.push_back(original[0] + original[1]);
            }
            sol.push_back(original[0] * 10 + original[1]);
        }
        else if (original.size() == 3)
        {
            if (original[2] != 0)
            {
                if (original[1] != 0)
                {
                    sol.push_back(original[0] + original[1] + original[2]);
                }
                sol.push_back(original[0] * 10 + original[1] + original[2]);
            }
            sol.push_back(original[0] + original[1] * 10 + original[2]);
            sol.push_back(original[0] * 100 + original[1] * 10 + original[2]);
        }
        return sol;
    }
    vector<string> makeTemplates(string s1)
    {
        vector<string> res;
        
    }

public:
    bool possiblyEquals(string s1, string s2)
    {
    }
};

int main()
{

    return 0;
}