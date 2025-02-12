#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        vector<int> costCum = vector<int>(n);
        costCum[0] = 0;
        costCum[1] = 0;
        for (int i = 2; i < n; i++)
        {
            int a = costCum[i-2] + cost[i-2];
            int b = costCum[i-1] + cost[i-1];
            costCum[i] = min(a,b);
        }
        return costCum[n-1];
    }
};

int main()
{
    Solution sol;
    vector<int> cost = {10,15,20};
    // vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << sol.minCostClimbingStairs(cost);
    return 0;
}