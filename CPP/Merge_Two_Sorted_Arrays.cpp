#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0;
        int j = 0;
        while (i < (j + m) && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                i++;
            }
            else
            {
                for (int k = m +n- 2; k >= i; k--)
                {
                    nums1[k + 1] = nums1[k];
                }
                nums1[i] = nums2[j];
                j++;
            }
        }
        if(j==n){
            return;
        }
        for (int k = i; k < m + n; k++)
            {
                nums1[k] = nums2[k - m];
            }
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {4,5,6,0,0,0};
        vector<int> nums2 = {1,2,3};
        sol.merge(nums1, 3, nums2, 3);

    // vector<int> nums1 = {1};
    // vector<int> nums2 = {};
    // sol.merge(nums1, 1, nums2, 0);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}