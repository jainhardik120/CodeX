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
        a = findParent(parent, a);
        b = findParent(parent, b);
        int u = rank[a];
        int v = rank[b];
        if (u < v)
        {
            parent[a] = b;
        }
        else if (v < u)
        {
            parent[b] = a;
        }
        else
        {
            parent[a] = b;
            rank[b]++;
        }
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 1)
        {
            return 0;
        }
        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                vector<int> edge(3);
                edge[0] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edge[1] = i;
                edge[2] = j;
                edges.push_back(edge);
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(n);
        vector<int> rank(n);
        int minDist = 0;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        for (auto edge : edges)
        {
            int a = findParent(parent, edge[1]);
            int b = findParent(parent, edge[2]);
            if (a != b)
            {
                unite(a, b, parent, rank);
                minDist += edge[0];
            }
        }
        return minDist;
    }
};

int main()
{

    return 0;
}