#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size()-1; i++)
        {
            for (int j = i+1; j < prices.size(); j++)
            {
                int temp = prices[i] - prices[j];
                if(temp>profit){
                    profit = temp;
                }
            }
            
        }
        return profit;
    }
};

int main()
{

    return 0;
}