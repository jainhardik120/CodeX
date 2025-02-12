#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> positions(n);
        for (int i = 0; i < n; i++)
        {
            positions[i] = i;
        }
        int size;
        int l;
        for (size = 1; size <= n - 1; size = 2 * size)
        {
            for (l = 0; l < n - 1; l += 2 * size)
            {
                int m = min(l + size - 1, n - 1);
                int r = min(l + 2 * size - 1, n - 1);
                int i, j, k;
                int n1 = m - l + 1;
                int n2 = r - m;
                int *left = new int[n1];
                int *right = new int[n2];
                int *newPositions = new int[n1 + n2];
                for (i = 0; i < n1; i++)
                    left[i] = nums[l + i];
                for (j = 0; j < n2; j++)
                    right[j] = nums[m + 1 + j];
                i = 0;
                j = 0;
                k = l;
                while (i < n1 && j < n2)
                {
                    if (left[i] <= right[j])
                    {
                        counts[positions[l + i]] += j;
                        newPositions[k - l] = positions[l + i];
                        nums[k] = left[i];
                        i++;
                    }
                    else
                    {
                        nums[k] = right[j];
                        newPositions[k - l] = positions[m + 1 + j];
                        j++;
                    }
                    k++;
                }
                while (i < n1)
                {
                    counts[positions[l + i]] += j;
                    nums[k] = left[i];
                    newPositions[k - l] = positions[l + i];
                    i++;
                    k++;
                }
                while (j < n2)
                {
                    nums[k] = right[j];
                    newPositions[k - l] = positions[m + 1 + j];
                    j++;
                    k++;
                }
                for (i = 0; i < n1 + n2; i++)
                {
                    positions[l+i] = newPositions[i];
                }
                delete[] newPositions;
                delete[] left;
                delete[] right;
            }
        }
        return counts;
    }
};

int main()
{

    return 0;
}