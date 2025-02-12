#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int len = customers.size();
        int count = 0;
        vector<int> countYes(len, 0);
        for (int i = 0; i < len; i++)
        {
            if (customers[i] == 'Y')
            {
                count++;
            }
            countYes[i] = count;
        }
        int min = INT_MAX;
        int index = 0;
        for (int i = 0; i < len + 1; i++)
        {
            int total;
            if (i == 0)
            {
                total = count;
            }
            else
            {
                total = count + i - (2 * countYes[i - 1]);
            }
            if (total < min)
            {
                min = total;
                index = i;
            }
        }

        return index;
    }
};

int main()
{
    Solution sol;
    sol.bestClosingTime("YYNY");
    return 0;
}