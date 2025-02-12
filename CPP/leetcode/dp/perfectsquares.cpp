#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        int *ans = new int[n + 1];
        ans[0] = 0;
        int maxYet = 0;
        int nextSqaure = 1;
        for (int i = 1; i < n + 1; i++)
        {
            if (i == nextSqaure)
            {
                ans[i] = 1;
                maxYet++;
                nextSqaure = (maxYet + 1) * (maxYet + 1);
            }
            else
            {
                int min = INT_MAX;
                for (int j = 1; j <= maxYet; j++)
                {
                    int temp = 1 + ans[i-(j*j)];
                    min = (min>temp)?temp:min;
                }
                ans[i] = min;
            }
        }
        int num = ans[n];
        delete[] ans;
        return num;
    }
};

int main()
{
    Solution sol;
    cout << sol.numSquares(13);
    return 0;
}