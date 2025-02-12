#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = vector<int>(n+1);
        ans[0] = 0;
        for (int i = 0; i < n+1; i++)
        {
            ans[i] = ans[i/2] + (i%2);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> ans = sol.countBits(10);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}