#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> ans;
    void helper(int begin, int target, vector<int> &candidates, vector<int> &tempAns)
    {
        if (target == 0)
        {
            ans.push_back(tempAns);
            return;
        }
        if (begin == candidates.size() || candidates[begin] > target)
        {
            return;
        }
        tempAns.push_back(candidates[begin]);
        helper(begin + 1, target - candidates[begin], candidates, tempAns);
        tempAns.pop_back();
        do
        {
            begin++;
        } while (begin + 1 < candidates.size() && candidates[begin + 1] == candidates[begin]);

        helper(begin, target, candidates, tempAns);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        ans.clear();
        vector<int> tempAns;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, tempAns);
        return ans;
    }
};

int main()
{

    return 0;
}