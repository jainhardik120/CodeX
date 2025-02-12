#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> ans;
        ans.push_back(first);
        for (int i = 0; i < encoded.size(); i++)
        {
            int a = encoded[i];
            int b = ans[i];
            ans.push_back(a^b);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> e = {1,2,3};
    vector<int> d = sol.decode(e, 1);
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    
    return 0;
}