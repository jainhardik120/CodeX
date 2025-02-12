#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool doesPosExist(int x, int y)
    {
        return ((x >= 0 && x < 8) && (y >= 0 && y < 8));
    }

public:
    bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color)
    {
        char oppColor;
        if (color == 'B')
        {
            oppColor = 'W';
        }
        else
        {
            oppColor = 'B';
        }
        vector<vector<int>> moves = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        for (auto move : moves)
        {
            int rowStart = rMove + move[0];
            int colStart = cMove + move[1];
            if (doesPosExist(rowStart, colStart) && board[rowStart][colStart] == oppColor)
            {
                while (doesPosExist(rowStart + move[0], colStart + move[1]) && board[rowStart + move[0]][colStart + move[1]] == oppColor)
                {
                    rowStart = rowStart + move[0];
                    colStart = colStart + move[1];
                }
                if(doesPosExist(rowStart, colStart) && board[rowStart][colStart]==oppColor){
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}