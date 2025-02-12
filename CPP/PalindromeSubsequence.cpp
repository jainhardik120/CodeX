#include <bits/stdc++.h>
using namespace std;

int calculateAns(vector<char> &s, vector<vector<int>> &dpStates, int i, int j)
{
  if (dpStates[i][j] != INT_MAX)
  {
    return dpStates[i][j];
  }
  if (i == j)
  {
    return dpStates[i][j] = 1;
  }
  int x = calculateAns(s, dpStates, i + 1, j);
  int y = calculateAns(s, dpStates, i, j - 1);
  if (s[i] == s[i + 1] || s[i] == s[j])
  {
    dpStates[i][j] = min(dpStates[i][j], x);
  }
  else
  {
    dpStates[i][j] = min(dpStates[i][j], x + 1);
  }
  if (s[j] == s[i] || s[j] == s[j - 1])
  {
    dpStates[i][j] = min(dpStates[i][j], y);
  }
  else
  {
    dpStates[i][j] = min(dpStates[i][j], y+1);
  }
  return dpStates[i][j];
}

int main()
{
  int n;
  cin >> n;
  vector<char> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  vector<vector<int>> dpStates(n, vector<int>(n, INT_MAX));
  int ans = calculateAns(s, dpStates, 0, n - 1);
  cout << ans << "\n";
  return 0;
}