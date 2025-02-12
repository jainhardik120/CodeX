#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void printGraph(vector<unordered_set<int>> &graph)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            cout << i << " : ";
            for (auto j : graph[i])
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges)
    {
        int n = coins.size();
        vector<unordered_set<int>> graph(n);
        unordered_set<int> removedIndexes;
        for (auto edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 1 && coins[i] == 0)
            {
                removedIndexes.insert(i);
                for (auto j : graph[i])
                {
                    graph[j].erase(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 1 && coins[i] == 1)
            {
                removedIndexes.insert(i);
                for (auto j : graph[i])
                {
                    removedIndexes.insert(j);
                }
            }
        }

        return (n-(removedIndexes.size()));
    }
};

int main()
{

    return 0;
}