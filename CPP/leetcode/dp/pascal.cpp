#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> row;
            for (int j = 0; j < i; j++)
            {
                if(j==0 || j==i-1){
                    row.push_back(1);
                }else{
                    row.push_back(ans[i-2][j]+ans[i-2][j-1]);
                }
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ans = sol.generate(5);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}