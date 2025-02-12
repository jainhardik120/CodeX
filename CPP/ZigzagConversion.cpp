#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ans = "";
        int incrementBy = ((numRows != 1) ? ((2 * (numRows - 1))) : 1);
        for (int i = 0; i < numRows; i++)
        {
            int itr = i;
            bool isMid = (i != 0) && (i != (numRows - 1));
            while (itr < s.length())
            {
                ans += s[itr];
                if (isMid)
                {
                    itr += (2 * (numRows - i - 1));
                    if (itr < s.length())
                    {
                        ans += s[itr];
                    }
                    itr += (2 * (i));
                }
                else
                {
                    itr += incrementBy;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.convert("paypalishiring", 3);
    return 0;
}