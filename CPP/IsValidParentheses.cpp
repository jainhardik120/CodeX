#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> stack;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }
                int top = stack.top();
                stack.pop();
                if (!((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')))
                {
                    return false;
                }
            }
        }
        if(stack.empty()){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s = "()[]{}";
    cout << sol.isValid(s);
    return 0;
}