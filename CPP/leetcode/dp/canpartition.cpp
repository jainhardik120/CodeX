#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<bool> constructDPArray(vector<int> &nums, int sum)
    {
        vector<bool> solution(sum + 1, false);
        solution[0] = true;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum+1; j >= nums[i]; j--)
            {
                if (!solution[j])
                {
                    solution[j] = solution[j - nums[i]];
                }
            }
        }
        return solution;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        vector<bool> sumArray = constructDPArray(nums, sum/2);
        for (int i = 0; i < sumArray.size(); i++)
        {
            cout << sumArray[i] << " ";
        }
        
        return sumArray[sum/2];
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1,2,5};
    sol.canPartition(nums);
    return 0;
}