#include <bits/stdc++.h>

using namespace std;

int findParent(vector<int> &parents, int i)
{
  if (parents[i] == i)
    return i;
  return parents[i] = findParent(parents, parents[i]);
}

vector<int> findAns(int pods, vector<vector<int>> &connections, vector<vector<int>> &queries, int n)
{

  vector<int> parents(pods);
  for (int i = 0; i < pods; i++)
  {
    parents[i] = i;
  }

  for (auto conn : connections)
  {
    int x = findParent(parents, conn[0] - 1);
    int y = findParent(parents, conn[1] - 1);
    if (x == y)
      continue;
    parents[x] = y;
  }
  unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
  for (int i = 0; i < n; i++)
  {
    int x = findParent(parents, i);
    map[x].push(i);
  }
  vector<bool> isFailed(n, false);
  vector<int> ans;
  for (auto query : queries)
  {
    if (query[0] == 2)
    {
      isFailed[query[1] - 1] = true;
    }
    else
    {
      if (!isFailed[query[1] - 1])
      {
        ans.push_back(query[1]);
      }
      else
      {
        int x = parents[query[1] - 1];
        while (!map[x].empty() && isFailed[map[x].top()])
        {
          map[x].pop();
        }
        if (map[x].empty())
        {
          ans.push_back(-1);
        }
        else
        {
          ans.push_back(map[x].top());
        }
      }
    }
  }
  return ans;
}

int main()
{
  int pods;
  cin >> pods;
  int n;
  cin >> n;
  vector<vector<int>> connections(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> connections[i][0] >> connections[i][1];
  }
  int q;
  cin >> q;
  vector<vector<int>> queries(q, vector<int>(2));
  for (int i = 0; i < q; i++)
  {
    cin >> queries[i][0] >> queries[i][1];
  }
  vector<int> ans = findAns(pods, connections, queries, n);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  return 0;
}