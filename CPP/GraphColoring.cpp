#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, M, g[N][N];
int color[N];

bool dfs(int u, int c)
{
    color[u] = c;
    for (int v = 0; v < n; v++)
    {
        if (g[u][v] && (color[v] == c || (color[v] == -1 && !dfs(v, (c + 1) % M))))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> M >> m;
    memset(g, 0, sizeof g);
    memset(color, -1, sizeof color);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1 && !dfs(i, 0))
        {
            flag = false;
            break;
        }
    }
    cout << (flag ? 1 : 0) << endl;

    return 0;
}
