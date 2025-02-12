#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string last = countAndSay(n - 1);
        string result = "";
        int freq = 1;
        int nextNumber = last[0] - '0';
        int itr = 1;
        while (itr < last.length())
        {
            if ((last[itr] - '0') == nextNumber)
            {
                freq++;
            }
            else
            {
                result += (char)(freq + '0');
                result += (char)(nextNumber + '0');
                nextNumber = last[itr] - '0';
                freq = 1;
            }
            itr++;
        }
        result += (char)(freq + '0');
        result += (char)(nextNumber + '0');
        cout << n << " : " << result << "\n";
        return result;
    }
};

int main()
{
    Solution sol;
    sol.countAndSay(30);
    return 0;
}