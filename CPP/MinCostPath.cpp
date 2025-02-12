#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(vector<int> &v)
{
    int n = v.size();
    vector<int> dp(n);
    dp[n - 1] = 0;
    if (n == 1)
    {
        return 0;
    }
    dp[n - 2] = abs(v[n - 2] - v[n - 1]);
    for (int i = n - 3; i >= 0; i--)
    {
        int minC = INT_MAX;
        if(i+1 < n){
            minC = min(minC, dp[i+1] + abs(v[i]-v[i+1]));
        }
        if(i+2 < n){
            minC = min(minC, dp[i+2] + abs(v[i]-v[i+2]));
        }
        if(i+3 < n){
            minC = min(minC, dp[i+3] + abs(v[i]-v[i+3]));
        }
        dp[i] = minC;
    }
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int t = 0; t < n; t++)
    {
        int x;
        cin >> x;
        v[t] = x;
    }
    int result = minCost(v);

    cout <<  result << endl;

    return 0;
}
