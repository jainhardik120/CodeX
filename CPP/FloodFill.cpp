#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<char>> &board, unordered_set<int> &visited, int i, int j, int m, int n)
    {
        int x = (n * i) + j;
        if (visited.find(x) != visited.end())
        {
            return;
        }
        visited.insert(x);
        vector<int> a{-1, 0, 1, 0};
        vector<int> b{0, 1, 0, -1};
        for (int x = 0; x < 4; x++)
        {
            if (i + a[x] >= 0 && i + a[x] < m && j + b[x] >= 0 && j + b[x] < n && board[i + a[x]][j + b[x]] == 'O')
            {
                dfs(board, visited, i + a[x], j + b[x], m, n);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        unordered_set<int> set;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(board, set, 0, i, m, n);
            }
            if (board[m - 1][i] == 'O')
            {
                dfs(board, set, m - 1, i, m, n);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, set, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O')
            {
                dfs(board, set, i, n - 1, m, n);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && set.find((n * i) + j) == set.end())
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{

    return 0;
}