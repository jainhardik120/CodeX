#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void connect(int a, int b, vector<pair<int, vector<int>>> &nodes)
    {
        nodes[a].second.push_back(b);
    }

    void dfs(vector<pair<int, vector<int>>> &nodes, vector<bool> &visited, int init)
    {
        visited[init] = true;
        for (auto i : nodes[init].second)
        {
            if (!visited[i])
            {
                dfs(nodes, visited, i);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, vector<int>>> nodes((m * n) + 1);
        nodes[m * n].first = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nodes[(i * n) + j].first = grid[i][j];
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        connect((i * n) + j, m * n, nodes);
                        connect(m * n, (i * n) + j, nodes);
                    }
                }
                if (grid[i][j] == 1)
                {
                    if (i != 0 && grid[i - 1][j] == 1)
                    {
                        connect((i * n) + j, ((i - 1) * n) + j, nodes);
                    }
                    if (j != 0 && grid[i][j - 1] == 1)
                    {
                        connect((i * n) + j, ((i)*n) + j - 1, nodes);
                    }
                    if (i != m - 1 && grid[i + 1][j] == 1)
                    {
                        connect((i * n) + j, ((i + 1) * n) + j, nodes);
                    }
                    if (j != n - 1 && grid[i][j + 1] == 1)
                    {
                        connect((i * n) + j, ((i)*n) + j + 1, nodes);
                    }
                }
            }
        }
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].first == 1)
            {
                cout << i << " ";
                for (auto connected : nodes[i].second)
                {
                    cout << connected << " ";
                }
                cout << "\n";
            }
        }
        vector<bool> visited(m * n + 1, false);
        dfs(nodes, visited, m * n);
        for (auto i : visited)
        {
            cout << i << " ";
        }
        int count = 0;
        for (int i = 0; i < visited.size(); i++)
        {
            if (nodes[i].first == 1 && !visited[i])
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}