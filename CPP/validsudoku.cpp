#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<bool> visited(9, false);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (visited[num - 1])
                    {
                        return false;
                    }
                    else
                    {
                        visited[num - 1] = true;
                    }
                }
            }
        }
        cout << "Rows Done";

        for (int i = 0; i < 9; i++)
        {
            vector<bool> visited(9, false);
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    int num = board[j][i] - '0';
                    if (visited[num - 1])
                    {
                        return false;
                    }
                    else
                    {
                        visited[num - 1] = true;
                    }
                }
            }
        }
        cout << "Cols Done";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                vector<bool> visited(9, false);
                cout << "\n"
                     << i << " " << j << "\n";
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        cout << "\n"
                             << x << " " << y << "\n";
                        char ch = board[((i * 3) + x)][((j * 3) + y)];
                        if (ch != '.')
                        {
                            int num = ch - '0';
                            cout << num;
                            if (visited[num - 1])
                            {
                                return false;
                            }
                            else
                            {
                                visited[num - 1] = true;
                            }
                        }
                    }
                }
            }
        }
        cout << "Box Done";
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << sol.isValidSudoku(board);
    return 0;
}