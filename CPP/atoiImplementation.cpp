#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = 0;
        int isNegative = false;
        bool isFirstDigitFound = false;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (!isFirstDigitFound)
            {
                if (c == ' ')
                {
                    continue;
                }
                else if (c == '-')
                {
                    isNegative = true;
                    isFirstDigitFound = true;
                }
                else if (c == '+')
                {
                    isNegative = false;
                    isFirstDigitFound = true;
                }
                else
                {
                    if (c >= 48 && c <= 57)
                    {
                        isFirstDigitFound = true;
                        n += (c - 48);
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            else
            {
                if (c >= 48 && c <= 57)
                {
                    if(isNegative){
                        if(n > -1*((INT_MIN+(c-48))/10)){
                            return INT_MIN;
                        }
                    }else{
                        if(n > ((INT_MAX-(c-48))/10)){
                            return INT_MAX;
                        }
                    }
                    n *= 10;
                    n += (c - 48);
                }
                else
                {
                    if (isNegative)
                    {
                        return n * -1;
                    }
                    else
                    {
                        return n;
                    }
                }
            }
        }
        if (isNegative)
        {
            return n * -1;
        }
        else
        {
            return n;
        }
    }
};

int main()
{
    Solution sol;
    string s = "-9";
    cout << sol.myAtoi(s);
    return 0;
}