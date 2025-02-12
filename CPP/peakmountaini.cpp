#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int a = 0;
        int b = arr.size() - 1;
        while (a <= b)
        {
            int mid = (a + b) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] > arr[mid - 1])
            {
                a = mid + 1;
            }
            else if (arr[mid] > arr[mid + 1])
            {
                b = mid - 1;
            }
        }
        return a;
    }
};

int main()
{

    return 0;
}