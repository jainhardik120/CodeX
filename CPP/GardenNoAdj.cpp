#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<vector<int>> graph(n, vector<int>());
        for (auto edge : paths)
        {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        vector<int> gardens(n, -1);
        for (int i = 0; i < n; i++)
        {
            vector<bool> connectedGardens(4);
            for (auto j : graph[i])
            {
                if (gardens[j] != -1)
                {
                    connectedGardens[gardens[j] - 1] = true;
                }
            }
            for (int j = 0; j < 4; j++)
            {
                if (!connectedGardens[j])
                {
                    gardens[i] = j + 1;
                    break;
                }
            }
        }
        return gardens;
    }
};

int main()
{

    return 0;
}