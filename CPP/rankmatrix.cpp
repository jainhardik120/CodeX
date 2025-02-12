#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

class Solution
{
    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }
    void unite(int a, int b, vector<int> &parent, vector<int> &rank)
    {
        int u = findParent(parent, a);
        int v = findParent(parent, b);
        if (u == v)
        {
            return;
        }
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }

public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ascending;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ascending.push_back({matrix[i][j], i, j});
            }
        }
        sort(ascending.begin(), ascending.end(), cmp);
        int itr = 0;
        vector<vector<int>> rankMatrix(m, vector<int>(n, 0));
        vector<int> rowsMax(m, 0);
        vector<int> colsMax(n, 0);
        while (itr < m * n)
        {
            vector<int> rows;
            vector<int> cols;
            int curr = ascending[itr][0];
            rows.push_back(ascending[itr][1]);
            cols.push_back(ascending[itr][2]);
            while (itr < ((m * n) - 1) && ascending[itr + 1][0] == curr)
            {
                itr++;
                rows.push_back(ascending[itr][1]);
                cols.push_back(ascending[itr][2]);
            }
            itr++;

            
            int x = rows.size();
            vector<int> parent(x);
            vector<int> rank(x, 0);
            for (int i = 0; i < x; i++)
            {
                parent[i] = i;
            }
            for (int i = 0; i < x - 1; i++)
            {
                for (int j = i + 1; j < x; j++)
                {
                    if (rows[i] == rows[j] || cols[i] == cols[j])
                    {
                        unite(i, j, parent, rank);
                    }
                }
            }
            unordered_map<int, vector<pair<int, int>>> map;
            for (int i = 0; i < x; i++)
            {
                map[findParent(parent, i)].push_back({rows[i], cols[i]});
            }

            for (auto i : map)
            {
                int max = 0;
                for (auto j : i.second)
                {
                    if (rowsMax[j.first] > max)
                    {
                        max = rowsMax[j.first];
                    }
                    if (colsMax[j.second] > max)
                    {
                        max = colsMax[j.second];
                    }
                }
                max++;
                for (auto j : i.second)
                {
                    rankMatrix[j.first][j.second] = max;
                    rowsMax[j.first] = max;
                    colsMax[j.second] = max;
                }
            }
        }
        return rankMatrix;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = 
    {{28, -13, 42, 49, -20, -9, -46, 21, -8, -25, -18, -39, -8, -13, 6, -7, -44, -33}, 
    {-30, 9, 4, -45, 14, -7, 44, 47, -30, 9, -40, 43, -50, -15, 36, -1, 46, -35}, 
    {-24, 19, 2, -27, -20, 23, 6, -39, 32, 3, -14, -47, -36, 23, -10, 17, 32, 27}, 
    {42, 9, 40, 11, -38, -23, 16, -13, -30, -3, -32, -5, -6, -35, 32, -1, 30, 33}, 
    {32, -33, 26, 49, -32, -25, 22, -7, 8, -1, -26, 21, -28, 31, 22, 33, 28, 47}, 
    {-46, 37, -4, -1, -22, -35, -48, -37, -2, 37, -16, -5, 6, 17, -36, 3, 30, 41}, 
    {40, 19, 38, -3, -12, -29, 14, -7, -44, 19, -10, 49, -8, -5, -6, -31, -12, -49}, 
    {6, -35, -16, -5, 22, -27, 24, 35, 2, 45, -8, -49, 10, -43, -36, 11, 34, -39}, 
    {-4, -21, 18, -7, 24, -21, 26, 1, 12, 15, 46, -35, -20, 7, -26, 1, 36, 39}, 
    {-14, 33, -16, 43, 42, 49, 12, -17, -18, 49, -16, 3, -34, 49, -24, -29, -6, -47}, 
    {-4, -21, 46, 1, 8, -41, 18, -43, 4, 35, -46, 13, 4, 47, -30, -7, 4, 43}, 
    {-18, -11, 4, -21, 38, 1, 32, -49, 10, 37, 12, 19, 2, -27, 32, -33, -46, 33}, 
    {-36, 11, -38, 17, -20, 15, 26, -39, -48, -29, -42, -15, -32, 35, -6, 49, 24, -21}, 
    {-14, 33, -20, -41, -6, 5, 8, -49, -46, 41, -24, -21, -38, -35, 28, -1, 2, -43}, 
    {44, -37, 18, 45, 36, 23, -26, 21, 44, -21, -46, -47, 24, 35, 22, -7, 40, 47}, 
    {10, -7, -16, -33, 38, -23, 0, -33, -38, -39, -16, 27, 14, 49, 24, 15, -38, -19}, 
    {36, -1, -6, -19, 4, -17, 46, -23, 8, -9, 42, -43, -48, 31, -30, -3, 0, 31}, 
    {-10, -23, -20, 15, 30, -7, 16, 43, 18, 17, 32, -29, -38, 17, 24, -13, 6, -27}};
    vector<vector<int>> rank = sol.matrixRankTransform(grid);
    for (int i = 0; i < rank.size(); i++)
    {
        for (int j = 0; j < rank[0].size(); j++)
        {
            cout << rank[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}