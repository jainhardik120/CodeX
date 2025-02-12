#include <bits/stdc++.h>
using namespace std;

class Solution
{
    pair<bool, vector<vector<int>>> findTarget(vector<int> &candidates, int target, int begin)
    {
        vector<vector<int>> sol;
        if (begin == candidates.size())
        {
            return sol;
        }
        if (candidates[begin] > target)
        {
            return sol;
        }
        vector<int> a = findTarget(candidates, );
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
    }
};

int main()
{

    return 0;
}