#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxStrength(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 1;
        bool flag = false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                flag=true;
                ans *= nums[i];
            }
            else if (nums[i] < 0)
            {
                if(i+1<n && nums[i+1]<0){
                    flag=true;
                    ans*=nums[i];
                    ans*=nums[++i];
                }
            }
        }
        if(!flag){
            return nums[n-1];
        }
        return ans;
    }
};

int main()
{

    return 0;
}