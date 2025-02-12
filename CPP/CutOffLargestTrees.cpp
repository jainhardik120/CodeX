#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dfs(int i, int j, int x, int y, vector<vector<int>> &forest, int m, int n, vector<vector<bool>> &visited)
    {
        if (i == x && j == y)
        {
            return 0;
        }
        if (forest[i][j] == 0)
        {
            return -1;
        }
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int min = INT_MAX;
        bool flag = false;
        for (auto direction : directions)
        {
            int i1 = i + direction[0];
            int j1 = j + direction[1];
            if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && forest[i1][j1] > forest[i][j])
            {
                if (!visited[i1][j1])
                {
                    visited[i1][j1] = true;
                    int a = dfs(i1, j1, x, y, forest, m, n, visited);
                    if (a != -1)
                    {
                        flag = true;
                        if (a < min)
                        {
                            min = a;
                        }
                    }
                    visited[i1][j1] = false;
                }
            }
        }
        if (!flag)
        {
            return -1;
        }
        return (min + 1);
    }

public:
    int cutOffTree(vector<vector<int>> &forest)
    {
        int m = forest.size();
        int n = forest[0].size();
        int x, y;
        int maxTree = INT_MIN;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maxTree < forest[i][j])
                {
                    maxTree = forest[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        return dfs(0, 0, x, y, forest, m, n, visited);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> forest = {{54581641, 64080174, 24346381, 69107959}, {86374198, 61363882, 68783324, 79706116}, {668150, 92178815, 89819108, 94701471}, {83920491, 22724204, 46281641, 47531096}, {89078499, 18904913, 25462145, 60813308}};
    cout << sol.cutOffTree(forest);
    return 0;
}