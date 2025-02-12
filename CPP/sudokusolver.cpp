#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isFilled(vector<vector<char>> &board, int i, int j)
    {
        bool filled = (board[i][j] != '.');
        return filled;
    }

    bool isValid(vector<vector<char>> &board, int m, int n, int val)
    {
        if (isFilled(board, m, n))
        {
            return false;
        }
        char ch = val + '0';
        for (int i = 0; i < 9; i++)
        {
            if (board[m][i] == ch)
            {
                return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (board[i][n] == ch)
            {
                return false;
            }
        }
        int x = m / 3;
        int y = n / 3;
        for (int i = 3 * x; i < 3 * (x + 1); i++)
        {
            for (int j = 3 * y; j < 3 * (y + 1); j++)
            {
                if (board[i][j] == ch)
                {
                    return false;
                }
            }
        }
        return true;
    }

    pair<int, int> cellFromInt(int x)
    {
        int i = x / 9;
        int j = x % 9;
        return pair<int, int>(i, j);
    }

    bool isFilledFromInt(vector<vector<char>> &board, int x)
    {
        pair<int, int> cell = cellFromInt(x);
        return isFilled(board, cell.first, cell.second);
    }

    bool solve(vector<vector<char>> &board, int emptyCells, int lastCell)
    {
        if (emptyCells == 0)
        {
            return true;
        }
        int nextCell = lastCell + 1;
        while (isFilledFromInt(board, nextCell))
        {
            nextCell++;
        }
        pair<int, int> cell = cellFromInt(nextCell);
        cout << cell.first << " " << cell.second << "\n";
        for (int i = 1; i <= 9; i++)
        {
            if (isValid(board, cell.first, cell.second, i))
            {
                board[cell.first][cell.second] = '0' + i;
                if (solve(board, emptyCells - 1, nextCell))
                {
                    return true;
                }
                else
                {
                    board[cell.first][cell.second] = '.';
                }
            }
        }
        return false;
    }

    
public:
void printBoard(vector<vector<char>> &board){
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        int emptyCount = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    emptyCount++;
                }
            }
        }
        solve(board, emptyCount, -1);
    }
};

int main()
{
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;
    // sol.printBoard(board);
    sol.solveSudoku(board);
    sol.printBoard(board);
    return 0;
}