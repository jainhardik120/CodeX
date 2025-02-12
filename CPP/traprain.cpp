#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            left[i] = max;
            if (height[i] > max)
            {
                max = height[i];
            }
        }
        max = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = max;
            if (height[i] > max)
            {
                max = height[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int min = left[i];
            if (right[i] < min)
            {
                min = right[i];
            }
            min-=height[i];
            if(min>0){
                ans += min;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}