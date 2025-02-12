#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        vector<int> ans = triangle[n-1];
        int itr = n-1;
        while(itr>0){
            vector<int> newAns;
            for (int i = 0; i < itr; i++)
            {
                newAns.push_back(triangle[itr-1][i] + min(ans[i], ans[i+1]));
            }
            ans.clear();
            ans = newAns;
            itr--;
        }
        return ans[0];
    }
};

int main(){
    vector<vector<int>> triangle{
        {-11},
        {-10, 10}
    };
    // vector<vector<int>> triangle{
    //     {2},
    //     {3,4},
    //     {6,5,7},
    //     {4,1,8,3}
    // };
    Solution sol;
    cout << sol.minimumTotal(triangle);
    return 0;
}