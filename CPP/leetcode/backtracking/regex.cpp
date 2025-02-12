#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool matchHelper(string s, string p, int i, int j){
        if((i==s.length())&&(j==p.length())){
            return true;
        }
        if(i==s.length()){
            return false;
        }
        if(j==p.length()){
            return false;
        }
    }

public:
    bool isMatch(string s, string p)
    {
        matchHelper(s,p,0,0);
        // int i = 0;
        // int j = 0;
        // int m = s.length();
        // int n = p.length();
        // while (i < m && j < n)
        // {
        //     if (p[j + 1] == '*')
        //     {
        //         while ((s[i] == p[j] || p[j] == '.')&&i<m)
        //         {
        //             if(((j+2)<m)&&(s[i]==p[j+2])){
                        
        //             }else{
        //                 i++;
        //             }
        //         }
        //         j += 2;
        //     }
        //     else if (p[j] == '.')
        //     {
        //         i++;
        //         j++;
        //     }else if(p[j]==s[i]){
        //         i++;
        //         j++;
        //     }
        //     // cout << i << " " << j << "\n";
        // }
        // if (i == m && j == n)
        // {
        //     return true;
        // }
        // return false;
    }
};

int main()
{
    Solution sol;
    string s = "ab";
    string p = ".*";
    cout << sol.isMatch(s, p);
    return 0;
}