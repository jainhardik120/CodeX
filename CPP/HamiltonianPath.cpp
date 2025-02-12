#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int g[N][N];
vector<int> path;
bool used[N];

bool dfs(int u) {
  if (u == n - 1) {
    path.push_back(u);
    return true;
  }
  used[u] = true;
  path.push_back(u);
  for (int v = 0; v < n; v++) {
    if (g[u][v] && !used[v] && dfs(v)) {
      return true;
    }
  }
  path.pop_back();
  used[u] = false;
  return false;
}

int main() {
  cin >> n >> m;
  memset(g, 0, sizeof g);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u][v] = g[v][u] = 1;
  }
  memset(used, 0, sizeof used);
  if (dfs(0)) {
    cout << "1\n";
    cout << "Hamiltonian Path found: ";
    for (int i = 0; i < path.size(); i++) {
      cout << path[i] + 1 ;
      if(i!=path.size()-1){
        cout << " -> ";
      }
    }
    cout << endl;
  } else {
    cout << "0\n";
    // cout << "No Hamiltonian Path found" << endl;
  }
  return 0;
}
