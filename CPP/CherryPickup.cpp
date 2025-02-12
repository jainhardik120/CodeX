#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> dpMax(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int movements[][4] = {{-1, 0, -1, 0}, {0, -1, 0, -1}, {0, -1, -1, 0}, {-1, 0, 0, -1}};
        int a, b, c, d;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int p = 0; p < n; p++)
                {
                    if (i == 0 && j == 0 && p == 0)
                    {
                        dpMax[i][j][p] = grid[0][0];
                        continue;
                    }
                    int q = ((i + j) - p);
                    if (q < 0 || q >= n)
                    {
                        continue;
                    }
                    if (grid[i][j] == -1 || grid[p][q] == -1)
                    {
                        continue;
                    }
                    int maxRes = -1;
                    for (int l = 0; l < 4; l++)
                    {
                        a = i + movements[l][0];
                        b = j + movements[l][1];
                        c = p + movements[l][2];
                        d = q + movements[l][3];
                        if (a < 0 || b < 0 || c < 0 || d < 0)
                        {
                            continue;
                        }
                        maxRes = max(maxRes, dpMax[a][b][c]);
                    }
                    if (maxRes == -1)
                    {
                        dpMax[i][j][p] = -1;
                    }
                    else
                    {
                        if (i == p)
                        {
                            dpMax[i][j][p] = maxRes + grid[i][j];
                        }
                        else
                        {
                            dpMax[i][j][p] = maxRes + grid[i][j] + grid[p][q];
                        }
                    }
                }
            }
        }
        if(dpMax[n-1][n-1][n-1]==-1){
            return 0;
        }
        return dpMax[n-1][n-1][n-1];
    }
};

int main()
{

    return 0;
}