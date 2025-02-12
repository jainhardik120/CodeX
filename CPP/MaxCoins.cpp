#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dpMatrix(n, vector<int>(n, 0));
        int a, b, c;
        for (int len = 0; len < n; len++)
        {
            for (int i = 0; i < (n - len); i++)
            {
                int j = (i + len);
                int res = 0;
                for (int k = i; k <= j; k++)
                {
                    if (k == i)
                    {
                        a = 0;
                    }
                    else
                    {
                        a = dpMatrix[i][k - 1];
                    }
                    if (k == j)
                    {
                        c = 0;
                    }
                    else
                    {
                        c = dpMatrix[k + 1][j];
                    }
                    b = nums[k] * ((i != 0) ? (nums[i - 1]) : 1) * ((j != n - 1) ? (nums[j + 1]) : 1);
                    res = max(res, (a + b + c));
                }
                dpMatrix[i][j] = res;
            }
        }
        return dpMatrix[0][n - 1];
    }
};

int main()
{

    return 0;
}