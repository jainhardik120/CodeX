#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> findSolutions(vector<int> &path, int start, int n)
    {
        vector<vector<int>> sol;
        if (start == n)
        {
            sol.push_back(path);
            return sol;
        }
        vector<bool> possiblePositions(n, true);
        int leftDiagonal, rightDiagonal;
        for (int i = 0; i < start; i++)
        {
            possiblePositions[path[i]] = false;
            leftDiagonal = path[i] - (start - i);
            rightDiagonal = path[i] + (start - i);
            if (leftDiagonal >= 0 && leftDiagonal < n)
            {
                possiblePositions[leftDiagonal] = false;
            }
            if (rightDiagonal >= 0 && rightDiagonal < n)
            {
                possiblePositions[rightDiagonal] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (possiblePositions[i])
            {
                path.push_back(i);
                auto backSols = findSolutions(path, start + 1, n);
                sol.insert(sol.end(), backSols.begin(), backSols.end());
                path.pop_back();
            }
        }
        return sol;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> path;
        vector<vector<string>> ans;
        auto solution = findSolutions(path, 0, n);
        string dots = "";
        for (int i = 0; i < n; i++)
        {
            dots += ".";
        }
        for (auto i : solution)
        {
            vector<string> sol;
            for (auto j : i)
            {
                dots[j] = 'Q';
                sol.push_back(dots);
                dots[j] = '.';
            }
            ans.push_back(sol);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    auto j = sol.solveNQueens(4);
    for (auto i : j)
    {
        for (auto k : i)
        {
            cout << k << "\n";
        }
        cout << "----------\n";
    }
    return 0;
}