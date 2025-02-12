#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans = vector<vector<int>>(m+1, vector<int>(n+1));
        for (int i = 0; i < m+1; i++)
        {
            for (int j = 0; j < n+1; j++)
            {
                if(i==0 || j==0){
                    ans[i][j] = 0;
                } else if(i==1 && j==1){
                    ans[i][j] = 1;
                } else{
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];
                }
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        return ans[m][n];
    }
};

int main(){
    Solution sol;
    cout << sol.uniquePaths(10,10);
    return 0;
}