#include <bits/stdc++.h>
using namespace std;

int compute_max_value(vector<int> &a, vector<char> &op)
{
    int n = a.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

    for (int i = 0; i < n; i++)
    {
        dp[i][i].first = a[i];
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i <= n - length; i++)
        {
            int j = i + length - 1;
            for (int k = i; k < j; k++)
            {
                if (op[k] == '+')
                {
                    if (dp[i][j].first > dp[i][k].first + dp[k + 1][j].first)
                    {
                        dp[i][j].first = dp[i][j].first;
                    }
                    else
                    {
                        dp[i][j].first = dp[i][k].first + dp[k + 1][j].first;
                        dp[i][j].second = k;
                    }
                }
                else
                {
                    if (dp[i][j].first > dp[i][k].first - dp[k + 1][j].first)
                    {
                        dp[i][j].first = dp[i][j].first;
                    }
                    else
                    {
                        dp[i][j].first = dp[i][k].first - dp[k + 1][j].first;
                        dp[i][j].second = k;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j].first << " " << dp[i][j].second << " | ";
        }
        cout << "\n";
    }
    
    return dp[0][n - 1].first;
}

int main()
{
    vector<int> a = {1, 3, 2, 5, 1, 6, 7};
    vector<char> op = {'+', '-', '-', '+', '-', '+', '+'};
    int max_value = compute_max_value(a, op);
    cout << "Max value: " << max_value << endl;
    return 0;
}
