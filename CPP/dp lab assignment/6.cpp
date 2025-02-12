#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

vector<int> adj[MAXN];
int n;

int dfs(int u, int p, int &ans)
{
    vector<int> children;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        int subtree_size = dfs(v, u, ans);
        children.push_back(subtree_size);
    }
    sort(children.begin(), children.end());
    int sz = 1;
    for (int i = children.size() - 1; i >= 0; i--)
    {
        ans = max(ans, sz + children[i]);
        sz += children[i];
    }
    return sz;
}

int main()
{
    int n = 12;
    vector<vector<int>> tree(n);
    tree[0] = {1, 2};
    tree[1] = {3, 4, 5};
    tree[2] = {6};
    tree[3] = {7, 8};
    tree[4] = {};
    tree[5] = {};
    tree[6] = {9, 10};
    tree[7] = {};
    tree[8] = {};
    tree[9] = {};
    tree[10] = {11};
    tree[11] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            int u = i;
            int v = tree[i][j];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int ans = 0;
    dfs(1, 0, ans);
    cout << ans << endl;
    return 0;
}
