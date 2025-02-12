#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int m = a.size();
        int n = b.size();
        int small = min(m, n);
        string ans = "";
        int carry = 0;
        for (int i = 0; i < small; i++)
        {
            int x = a[m - i - 1] - '0';
            int y = b[n - i - 1] - '0';
            int sum = (x ^ y) ^ carry;
            int cout = (x & y) | ((x ^ y) & carry);
            char ch = '0' + sum;
            ans = ch + ans;
            carry = cout;
        }
        if (m > n)
        {
            for (int i = (m - small) - 1; i >= 0; i--)
            {
                int x = a[i] - '0';
                int y = 0;
                int sum = (x ^ y) ^ carry;
                int cout = (x & y) | ((x ^ y) & carry);
                char ch = '0' + sum;
                ans = ch + ans;
                carry = cout;
            }
        }
        else if (n > m)
        {
            for (int i = (n - small) - 1; i >= 0; i--)
            {
                int x = b[i] - '0';
                int y = 0;
                int sum = (x ^ y) ^ carry;
                int cout = (x & y) | ((x ^ y) & carry);
                char ch = '0' + sum;
                ans = ch + ans;
                carry = cout;
            }
        }
        if(carry == 1){
            ans = '1' + ans;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout<<sol.addBinary("100", "110010") << "\n";
    cout<<sol.addBinary("11", "1") << "\n";
    return 0;
}