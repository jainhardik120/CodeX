#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxYet = INT_MIN;
        int maxSum = 0;     
        for (int i = 0; i < n; i++)
        {
            maxSum = maxSum+nums[i];
            if(maxYet<maxSum){
                maxYet = maxSum;
            }
            if(maxSum<0){
                maxSum=0;
            }
        }
        return maxYet;
    }
};

int main()
{

    return 0;
}