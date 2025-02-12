#include <bits/stdc++.h>
using namespace std;

class Solution
{
    
public:
    pair<int, int> solveBraces(string s, int begin)
    {
        int itr = begin + 1;
        int result = 0;
        int nextOperator = 0;
        int nextOperand = 0;
        while (s[itr] != ')' && itr < s.length())
        {
            while (s[itr] == ' ' && itr < s.length())
            {
                itr++;
            }
            if(itr==s.length()){
                break;
            }
            if (s[itr] == '+')
            {
                nextOperator = 0;
                itr++;
            }
            else if (s[itr] == '-')
            {
                nextOperator = 1;
                itr++;
            }
            else
            {
                if (s[itr] == '(')
                {
                    auto pr = solveBraces(s, itr);
                    itr = pr.second + 1;
                    nextOperand = pr.first;
                }
                else
                {
                    while (s[itr] >= '0' && s[itr] <= '9' && itr < s.length())
                    {
                        nextOperand *= 10;
                        nextOperand += (s[itr] - '0');
                        itr++;
                    }
                }
                if (nextOperator == 0)
                {
                    result += nextOperand;
                }
                else
                {
                    result -= nextOperand;
                }
                nextOperand = 0;
                nextOperator = 0;
            }
        }
        return {result,itr};
    }

    int calculate(string s)
    {
        string mod = "(" + s + ")";
        auto pr = solveBraces(mod, 0);
        return pr.first;
    }
};

int main()
{
    Solution sol;
    auto pr = sol.calculate("+48 - (- 2");
    cout << pr << "\n";
    return 0;
}