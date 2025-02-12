#include <bits/stdc++.h>
using namespace std;

class Solution
{
    pair<bool, vector<vector<int>>> targetSumFromI(vector<int> &nums, int target, int startIndex)
    {
        vector<vector<int>> sol;
        if (target == 0)
        {
            return {true, sol};
        }
        if (startIndex >= nums.size())
        {
            return {false, sol};
        }
        if (target < nums[startIndex])
        {
            return {false, sol};
        }
        bool flag = false;
        auto j = targetSumFromI(nums, target - nums[startIndex], startIndex);
        auto l = targetSumFromI(nums, target, startIndex + 1);
        if (j.first)
        {
            flag = true;
            if (j.second.size() == 0)
            {
                sol.push_back({nums[startIndex]});
            }
            else
            {
                for(auto i : j.second){
                    i.insert(i.begin(), nums[startIndex]);
                    sol.push_back(i);
                }
            }
        }
        if (l.first)
        {
            flag = true;
            if (l.second.size() == 0)
            {
                sol.push_back({nums[startIndex]});
            }
            else
            {
                for(auto i : l.second){
                    sol.push_back(i);
                }
            }
        }
        return {flag, sol};
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        auto res = targetSumFromI(candidates, target, 0);
        return res.second;
    }
};

int main()
{
    return 0;
}