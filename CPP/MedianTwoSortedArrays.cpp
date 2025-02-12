#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n2 < n1)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int size = (n1 + n2) / 2;
        int l = 0;
        int r = n1 - 1;
        int mid;
        int mid2;

        int l1, l2, r1, r2;
        while (1)
        {
            mid = (l + r) / 2;
            if(r<0){
                mid = -1;
            }
            mid2 = size - mid - 2;
            if (mid >= 0)
            {
                l1 = nums1[mid];
            }
            else
            {
                l1 = INT_MIN;
            }
            if (mid2 >= 0)
            {
                l2 = nums2[mid2];
            }
            else
            {
                l2 = INT_MIN;
            }
            if (mid + 1 < n1)
            {
                r1 = nums1[mid + 1];
            }
            else
            {
                r1 = INT_MAX;
            }
            if (mid2 + 1 < n2)
            {
                r2 = nums2[mid2 + 1];
            }
            else
            {
                r2 = INT_MAX;
            }
            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2)
                {
                    return min(r1, r2);
                }
                else
                {
                    return (max(l1, l2) + min(r1, r2)) / 2;
                }
            }
            else if (l1 > r2)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 3};
    vector<int> n2 = {2};
    cout << sol.findMedianSortedArrays(n1, n2);
    return 0;
}