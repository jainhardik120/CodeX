#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // int solve(int a, int b, string s, string res, int n)
    // {
    //     cout << a << " " << b << " " << res << "\n";
    //     while (s[a] == res[a] && a < n)
    //     {
    //         a++;
    //     }
    //     while (s[b] == res[b] && b >= 0)
    //     {
    //         b--;
    //     }
    //     if (a > b)
    //     {
    //         return 0;
    //     }
    //     if (a == b)
    //     {
    //         if (s[a] == res[a])
    //         {
    //             return 0;
    //         }
    //         else
    //         {
    //             return 1;
    //         }
    //     }
    //     int c = b;
    //     while (c > a && (res[c] == '.' && s[c] != s[a]) || (s[c] == res[c]) || (s[c] != s[a]))
    //     {
    //         c--;
    //     }

    //     for (int i = a; i <= c; i++)
    //     {
    //         res[i] = s[a];
    //     }
    //     return 1 + next;
    // }
    int turn(vector<vector<int>> &dpArray, string &s, int a, int b, int n)
    {
        if (a > b)
            return 0;
        else if (dpArray[a][b] > 0)
            return dpArray[a][b];
        else
        {
            dpArray[a][b] = turn(dpArray, s, a, b - 1, n) + 1;
            for (int k = a; k < b; k++)
            {
                if (s[b] == s[k])
                {
                    dpArray[a][b] = min(turn(dpArray, s, a, k, n) + turn(dpArray, s, k + 1, b-1, n), dpArray[a][b]);
                }
            }
            return dpArray[a][b];
        }
    }

public:
    int strangePrinter(string s)
    {
        int n = s.length();
        vector<vector<int>> dpArray(n, vector<int>(n, -1));
        int ans = turn(dpArray, s, 0, n - 1, n);
        for(auto i : dpArray){
            for(auto j : i){
                cout<<j << " ";
            }
            cout << "\n";
        }
        return ans;
    }

    // int strangePrinter(string s)
    // {
    //     string res = "";
    //     int n = s.length();
    //     for (
    //         int i = 0; i < n; i++)
    //     {
    //         res += ".";
    //     }
    //     return solve(0, n - 1, s, res, n);
    //     //  return solve(6,25, s, res, n);
    // }
};

int main()
{
    Solution sol;
    cout << sol.strangePrinter("322233213243");
    return 0;
}