#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /*
        a = a;
        e = a,e;
        i = a,e,i;
        o = a,e,i,o;
        u = a,e,i,o,u
    */
public:
    int countVowelStrings(int n)
    {
        int lastArr[] = {1, 1, 1, 1, 1};
        n--;
        while (n--)
        {
            int sum = 0;
            for (int i = 0; i < 5; i++)
            {
                sum+=lastArr[i];
                lastArr[i] = sum;
            }
        }
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += lastArr[i];
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    cout << sol.countVowelStrings(33);
    return 0;
}