#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//     vector<vector<int>> map;

//     bool match(string s, string p, int i, int j)
//     {
//         if (map[i][j] != -2)
//         {
//             return map[i][j];
//         }
//         if (i == s.length() && j == p.length())
//         {
//             return map[i][j] = true;
//         }
//         if (i == s.length())
//         {
//             while (j != p.length())
//             {
//                 if (p[j] != '*')
//                 {
//                     return map[i][j] = false;
//                 }
//                 j++;
//             }
//             return map[i][j] = true;
//         }
//         if (p[j] != '?' && p[j] != '*' && p[j] != s[i])
//         {
//             return map[i][j] = false;
//         }
//         if (p[j] == '?')
//         {
//             return map[i][j] = match(s, p, i + 1, j + 1);
//         }
//         if (p[j] == s[i])
//         {
//             return map[i][j] = match(s, p, i + 1, j + 1);
//         }
//         if (p[j] == '*')
//         {
//             bool a = match(s, p, i + 1, j);
//             bool b = match(s, p, i, j + 1);
//             bool c = match(s, p, i + 1, j + 1);
//             return map[i][j] = (a || b || c);
//         }
//         return map[i][j] = false;
//     }

// public:
//     bool isMatch(string s, string p)
//     {
//         map = vector<vector<int>>(s.length()+1, vector<int>(p.length()+1, -2));
//         for (int i = s.length(); i >=0 ; i--)
//         {
//             for (int j = p.length(); j >= 0; j--)
//             {
//                 match(s,p,i,j);
//             }

//         }

//         for (int i = 0; i < p.length()+1; i++)
//         {
//             for (int j = 0; j < s.length()+1; j++)
//             {
//                 cout << map[j][i] << " ";
//             }
//             cout << "\n";
//         }

//         return map[0][0];
//     }
// };

class SolutionA
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> map(n + 1, vector<bool>(m + 1, false));
        map[n][m] = true;
        for (int i = 0; i < m; i++)
        {
            map[n][i] = false;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            map[i][m] = (map[i + 1][m] && p[i] == '*');
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (p[i] == '*')
                {
                    map[i][j] = (map[i + 1][j + 1] || map[i][j + 1] || map[i + 1][j]);
                }
                else if (p[i] == '?')
                {
                    map[i][j] = map[i + 1][j + 1];
                }
                else if (p[i] == s[j])
                {
                    map[i][j] = map[i + 1][j + 1];
                }
                else
                {
                    map[i][j] = false;
                }
            }
        }
        return map[0][0];
    }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        string modifiedP = "";
        unordered_map<int, char> uniMap;
        int itr = 0;
        while (itr < p.length())
        {
            if (itr + 1 < p.length() && p[itr + 1] == '*')
            {
                modifiedP += '*';
                uniMap[modifiedP.size() - 1] = p[itr];
                itr += 2;
            }
            else
            {
                modifiedP += p[itr];
                itr++;
            }
        }

        int m = s.length();
        int n = modifiedP.length();
        vector<vector<bool>> map(n + 1, vector<bool>(m + 1, false));
        map[n][m] = true;
        for (int i = 0; i < m; i++)
        {
            map[n][i] = false;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            map[i][m] = (map[i + 1][m] && modifiedP[i] == '*');
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (modifiedP[i] == '*')
                {
                    bool a = map[i + 1][j + 1];
                    bool b = map[i][j + 1];
                    bool c = map[i + 1][j];
                    map[i][j] = ((((uniMap[i] == s[j])||(uniMap[i]=='.')) && (a || b)) || c);
                }
                else if (modifiedP[i] == '.')
                {
                    map[i][j] = map[i + 1][j + 1];
                }
                else if (modifiedP[i] == s[j])
                {
                    map[i][j] = map[i + 1][j + 1];
                }
                else
                {
                    map[i][j] = false;
                }
            }
        }
        return map[0][0];
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> pairs = {
        {"aa", "a*"}};
    for (auto pair : pairs)
    {
        cout << sol.isMatch(pair[0], pair[1]);
    }
    return 0;
}