#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<pair<int, int>> sortedArrayWithIndices;
        for (int i = 0; i < arr.size(); i++)
        {
            sortedArrayWithIndices.push_back({i, arr[i]});
        }
        sort(sortedArrayWithIndices.begin(), sortedArrayWithIndices.end(), compare);
        int rank = 0;
        int itr = 0;
        vector<int> ranks(arr.size());
        while (itr < sortedArrayWithIndices.size())
        {
            rank++;
            ranks[sortedArrayWithIndices[itr].first] = rank;
            while (itr + 1 < sortedArrayWithIndices.size() && sortedArrayWithIndices[itr].second == sortedArrayWithIndices[itr + 1].second)
            {
                ranks[sortedArrayWithIndices[++itr].first] = rank;
            }
            itr++;
        }
        return ranks;
    }
};

int main()
{

    return 0;
}