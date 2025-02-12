#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return sqrt((a.first * a.first) + (a.second * a.second)) > sqrt((b.first * b.first) + (b.second * b.second));
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
        for (auto i : points)
        {
            q.push({i[0], i[1]});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++)
        {
            auto j = q.top();
            ans.push_back({j.first, j.second});
            q.pop();
        }
        return ans;
    }
};

int main()
{

    return 0;
}