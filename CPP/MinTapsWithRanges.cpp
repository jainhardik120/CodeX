#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<pair<int, int>> rangeCovered;
        for (int i = 0; i < ranges.size(); i++)
        {
            rangeCovered.push_back({i - ranges[i], i + ranges[i]});
        }
        sort(rangeCovered.begin(), rangeCovered.end(), compare);
        int toBeCovered = 0;
        int itr = 0;
        int numOfTaps = 0;
        while (toBeCovered < n && itr < rangeCovered.size())
        {
            int maxDistCovered = -1;
            while (itr < rangeCovered.size() && rangeCovered[itr].first <= toBeCovered )
            {
                if (rangeCovered[itr].first <= toBeCovered && rangeCovered[itr].second >= (toBeCovered + 1) && rangeCovered[itr].second >= maxDistCovered)
                {
                    maxDistCovered = rangeCovered[itr].second;
                }
                itr++;
            }
            if (maxDistCovered == -1)
            {
                return -1;
            }
            numOfTaps++;
            toBeCovered = maxDistCovered;
        }
        if(toBeCovered<n){
            return -1;
        }
        return numOfTaps;
    }
};

int main()
{
    Solution sol;
    vector<int> ranges = {0,0,0,0};
    cout << sol.minTaps(3, ranges);
    return 0;
}