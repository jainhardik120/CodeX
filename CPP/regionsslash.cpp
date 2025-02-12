#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int calcIndex(int i, int j, int r, int n)
    {
        return (((n * i) + j) * 2) + r;
    }
    void connectInGraph(int i, int j, vector<vector<bool>> &graph)
    {
        graph[i][j] = true;
        graph[j][i] = true;
    }
    void dfs(vector<vector<bool>> &isConnected, vector<bool> &visited, int start, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (isConnected[start][i] && !visited[i])
            {
                visited[i] = true;
                dfs(isConnected, visited, i, n);
            }
        }
    }

public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        vector<vector<bool>> graph(n * n * 2, vector<bool>(n * n * 2, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                char ch = grid[i][j];
                if (ch == '/')
                {
                    if (j != 0)
                    {
                        connectInGraph(calcIndex(i, j, 0, n), calcIndex(i, j - 1, 1, n), graph);
                    }
                    if (i != 0)
                    {
                        char ch2 = grid[i - 1][j];
                        if (ch2 == '/')
                        {
                            connectInGraph(calcIndex(i, j, 0, n), calcIndex(i - 1, j, 1, n), graph);
                        }
                        else
                        {
                            connectInGraph(calcIndex(i, j, 0, n), calcIndex(i - 1, j, 0, n), graph);
                        }
                    }
                }
                else if (ch == '\\')
                {
                    if (j != 0)
                    {
                        connectInGraph(calcIndex(i, j, 0, n), calcIndex(i, j - 1, 1, n), graph);
                    }
                    if (i != 0)
                    {
                        char ch2 = grid[i - 1][j];
                        if (ch2 == '/')
                        {
                            connectInGraph(calcIndex(i, j, 1, n), calcIndex(i - 1, j, 1, n), graph);
                        }
                        else
                        {
                            connectInGraph(calcIndex(i, j, 1, n), calcIndex(i - 1, j, 0, n), graph);
                        }
                    }
                }
                else
                {
                    connectInGraph(calcIndex(i, j, 0, n), calcIndex(i, j, 1, n), graph);
                    if (j != 0)
                    {
                        connectInGraph(calcIndex(i, j, 0, n), calcIndex(i, j - 1, 1, n), graph);
                    }
                    if (i != 0)
                    {
                        char ch2 = grid[i - 1][j];
                        if (ch2 == '/')
                        {
                            connectInGraph(calcIndex(i, j, 1, n), calcIndex(i - 1, j, 1, n), graph);
                        }
                        else
                        {
                            connectInGraph(calcIndex(i, j, 1, n), calcIndex(i - 1, j, 0, n), graph);
                        }
                    }
                }
            }
        }
        int m = graph.size();
        int numRegions = 0;
        vector<bool> visited(m, false);
        for (int i = 0; i < m; i++)
        {
            if (!visited[i])
            {
                numRegions++;
                dfs(graph, visited, i, m);
            }
        }
        return numRegions;
    }
};

int main()
{

    return 0;
}