#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dmoves = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int directionFunc(int diff)
    {
        if (diff == 0)
        {
            return 0;
        }
        else
        {
            if (diff < 0)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
    void checkAndMove(int ii, int ij, int fi, int fj, unordered_map<int, vector<int>> &graph, vector<string> &pieces, vector<vector<int>> &initPositions, int i, int n, int &count)
    {
        int index = ((fi - 1) * 8) + (fj - 1);
        auto itr = graph.find(index);
        if (itr != graph.end())
        {
            return;
        }
        graph[index] = {((ii - 1) * 8) + (ij - 1), i};
        dfs(graph, pieces, initPositions, i + 1, n, count);
        graph.erase(index);
    }
    void simulateMove(unordered_map<int, vector<int>> &graph, int &count)
    {
        int n = graph.size();
        unordered_map<int, int> currMap;
        vector<vector<int>> directions(n);
        for (auto itr : graph)
        {
            currMap[itr.second[0]] = itr.second[1];

            directions[itr.second[1]] = {directionFunc((itr.first / 8) - (itr.second[0] / 8)), directionFunc((itr.first % 8) - (itr.second[0] % 8))};
        }
        int currTime = 0;
        bool flag = true;
        while (1)
        {
            
        }
    }
    void dfs(unordered_map<int, vector<int>> &graph, vector<string> &pieces, vector<vector<int>> &initPositions, int i, int n, int &count)
    {
        if (i == n)
        {
            simulateMove(graph, count);
            return;
        }
        bool straightMovements = (pieces[i] == "rook" || pieces[i] == "queen");
        bool diagonalMovements = (pieces[i] == "bishop" || pieces[i] == "queen");
        int nextI, nextJ, k;
        int ii = initPositions[i][0];
        int ij = initPositions[i][1];
        int fi, fj;
        checkAndMove(ii, ij, ii, ij, graph, pieces, initPositions, i, n, count);
        if (straightMovements)
        {
            for (k = 1; k <= 8; k++)
            {
                if (k == ii)
                {
                    continue;
                }
                checkAndMove(ii, ij, k, ij, graph, pieces, initPositions, i, n, count);
            }
            for (k = 1; k <= 8; k++)
            {
                if (k == ij)
                {
                    continue;
                }
                checkAndMove(ii, ij, ii, k, graph, pieces, initPositions, i, n, count);
            }
        }
        if (diagonalMovements)
        {
            for (k = 0; k < 4; k++)
            {
                fi = ii + dmoves[k][0];
                fj = ij + dmoves[k][1];
                while (fi > 0 && fi < 9 && fj > 0 && fj < 9)
                {
                    checkAndMove(ii, ij, fi, fj, graph, pieces, initPositions, i, n, count);
                    fi += dmoves[k][0];
                    fj += dmoves[k][1];
                }
            }
        }
    }

public:
    int countCombinations(vector<string> &pieces, vector<vector<int>> &positions)
    {
        int count = 0;
        unordered_map<int, vector<int>> graph;
        dfs(graph, pieces, positions, 0, pieces.size(), count);
        return count;
    }
};

int main()
{

    return 0;
}