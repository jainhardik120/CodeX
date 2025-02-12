#include <bits/stdc++.h>
using namespace std;

int max(int *arr, int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }
    int mid = start + (end - start) / 2;
    int m1 = max(arr, start, mid);
    int m2 = max(arr, mid + 1, end);
    if (m1 > m2)
    {
        return m1;
    }
    else
    {
        return m2;
    }
}

int sum(int *arr, int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }
    int mid = start + (end - start) / 2;
    int m1 = sum(arr, start, mid);
    int m2 = sum(arr, mid + 1, end);
    return m1 + m2;
}

int factorialHelper(int m, int n)
{
    if (m == n)
    {
        return m;
    }
    int mid = m + (n - m) / 2;
    int m1 = factorialHelper(m, mid);
    int m2 = factorialHelper(mid + 1, n);
    return m1 * m2;
}

int factorial(int n)
{
    return factorialHelper(1, n);
}

int count(int arr[], int low, int high, int x)
{

    if ((low > high) || (low == high && arr[low] != x))
        return 0;

    if (low == high && arr[low] == x)
        return 1;

    return count(arr, low,
                 (low + high) / 2, x) +
           count(arr, 1 + (low + high) / 2,
                 high, x);
}

int main()
{
    int arr[] = {2, 1, 8, 9, 3, 6, 7, 5};
    cout << max(arr, 0, 7) << endl;
    cout << sum(arr, 0, 7) << endl;
    cout << factorial(5) << endl;
    cout << count(arr, 0, 7, 8) << endl;
    return 0;
}