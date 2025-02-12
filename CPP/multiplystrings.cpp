#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        if (num2.length() == 1)
        {
            string result = "";
            int multiplier = num2[0] - '0';
            int carry = 0;
            int itr = num1.length() - 1;
            while (itr >= 0)
            {
                int prod = ((num1[itr] - '0') * multiplier) + carry;
                result = (char)((prod % 10) + '0') + result;
                carry = prod / 10;
                itr--;
            }
            if (carry != 0)
            {
                result = (char)(carry + '0') + result;
            }
            return result;
        }
        else
        {
            vector<string> results;
            int n = num2.length();
            string lastZeroes = "";
            for (int i = n - 1; i >= 0; i--)
            {
                string next = "";
                next += num2[i];
                next = multiply(num1, next);
                next = next + lastZeroes;
                results.push_back(next);
                lastZeroes = lastZeroes + "0";
            }
            int itr = 0;
            int sum = 0;
            string result = "";
            bool flag = true;
            while (flag || sum)
            {
                flag = false;
                for (int i = 0; i < results.size(); i++)
                {
                    int len = results[i].length();
                    if (itr < len)
                    {
                        flag = true;
                        sum += (results[i][len - itr - 1] - '0');
                    }
                }
                result = ((char)((sum % 10) + '0')) + result;
                sum = sum / 10;
                itr++;
            }
            itr = 0;
            while(result[itr]=='0'){
                itr++;
            }
            result = result.substr(itr);
            return result;
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.multiply("9012384384", "999999999999999999999999999999999");
    return 0;
}