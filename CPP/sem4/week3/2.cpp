#include <bits/stdc++.h>
using namespace std;

int singleSearch(int *arr, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (mid % 2 == 0)
    {
        if (arr[mid] == arr[mid + 1])
        {
            return singleSearch(arr, mid + 2, end);
        }
        else if (arr[mid] == arr[mid - 1])
        {
            return singleSearch(arr, start, mid - 2);
        }
        else
        {
            return arr[mid];
        }
    }
    else
    {
        if (arr[mid] == arr[mid - 1])
        {
            return singleSearch(arr, mid + 1, end);
        }
        else if (arr[mid] == arr[mid + 1])
        {
            return singleSearch(arr, start, mid - 1);
        }
        else
        {
            return arr[mid];
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 1, 3, 3, 4, 4, 5, 5, 7, 7, 8};
    cout << singleSearch(arr, 0, sizeof(arr) / sizeof(int) - 1);
    return 0;
}