#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<int>> graph(n, vector<int>(n, -1));
        for (auto i : times)
        {
            graph[i[0]-1][i[1]-1] = i[2];
        }
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[k] = 0;
        visited[k] = true;
        unordered_set<int> found;
        int current = k;
        while (true)
        {
            visited[current] = true;
            for (int i = 0; i < n; i++)
            {
                if (graph[current][i] == -1 || visited[i])
                {
                    continue;
                }
                found.insert(i);
                int distance = dist[current] + graph[current][i];
                if (distance < dist[i])
                {
                    dist[i] = distance;
                }
            }
            found.erase(current);
            if (found.empty())
            {
                break;
            }
            int minDist = INT_MAX;
            int index = 0;
            for (int a : found)
            {
                if (dist[a] < minDist)
                {
                    minDist = dist[a];
                    index = a;
                }
            }
            current = index;
        }
        int maxDist = INT_MIN;
        for (auto a : dist)
        {
            cout << a << " ";
            if(a> maxDist){
                maxDist = a;
            }
        }
        return maxDist;

    }
};

int main()
{
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << sol.networkDelayTime(times, 4, 2);
    return 0;
}