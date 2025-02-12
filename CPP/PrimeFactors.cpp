#include <bits/stdc++.h>
using namespace std;

class Solution
{
    

public:
int numOfPrimeFactors(int n)
    {
        int count = 0;
        while (n % 2 == 0)
        {
            cout << 2 << " ";
            count++;
            n /= 2;
        }
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            while (n % i == 0)
            {
                cout << i << " ";
                count++;
                n /= i;
            }
        }
        if (n > 2)
        {
            cout << n << " ";
            count++;
        }
        return count;
    }
    vector<int> waysToFillArray(vector<vector<int>> &queries)
    {
    }
};

int main()
{
    Solution sol;
    cout << sol.numOfPrimeFactors(660);
    return 0;
}