#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> ways(amount+1, 0);
        ways[0] = 1;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int leftAmount = i-coins[j];
                if(leftAmount>=0){
                    ways[i]+=ways[leftAmount];
                }
            }
        }
        for (int i = 0; i < amount+1; i++)
        {
            cout << ways[i] << " ";
        }
        
        return ways[amount];
    }
};

int main()
{
    Solution sol;
    vector<int> coins{1,2,5};
    cout << sol.change(5, coins);
    return 0;
}