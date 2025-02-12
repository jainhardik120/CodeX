#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int findPathsHelper(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &answer)
    {
        const unsigned int M = 1000000007;
        if (maxMove == 0 || startRow < 0 || startColumn < 0 || startColumn > n - 1 || startRow > m - 1)
        {
            return 0;
        }
        if (answer[maxMove][startRow][startColumn] == -1)
        {
            int count = 0;
            if (startColumn == 0)
            {
                count++;
            }
            if (startRow == 0)
            {
                count++;
            }
            if (startColumn == n - 1)
            {
                count++;
            }
            if (startRow == m - 1)
            {
                count++;
            }
            count += findPathsHelper(m, n, maxMove - 1, startRow, startColumn + 1, answer);
            count = count%M;
            count += findPathsHelper(m, n, maxMove - 1, startRow, startColumn - 1, answer);
            count = count%M;
            count += findPathsHelper(m, n, maxMove - 1, startRow + 1, startColumn, answer);
            count = count%M;
            count += findPathsHelper(m, n, maxMove - 1, startRow - 1, startColumn, answer);
            count = count%M;
            return answer[maxMove][startRow][startColumn] = count;
        }
        else
        {
            return answer[maxMove][startRow][startColumn];
        }
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> answer = vector<vector<vector<int>>>(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        int solution =  findPathsHelper(m,n,maxMove, startRow, startColumn, answer);
        return solution;
    }
};

int main()
{
    Solution sol;
    cout << sol.findPaths(8,50,23,5,26);
    // cout << sol.findPaths(1, 3, 3, 0, 1);
    return 0;
}