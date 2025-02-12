#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
    double dist;
};

double distance(int x, int y)
{
    return sqrt((float)(x * x + y * y));
}

int partition(point arr[], int low, int high)
{
    point pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].dist < pivot.dist)
        {
            i++;
            point temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    point temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(point arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    point *arr = new point[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i].x = a;
        arr[i].y = b;
        arr[i].dist = distance(a, b);
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < k; i++)
    {
        cout << "[" << arr[i].x << ", " << arr[i].y << "]";
        if(i!=k-1){
            cout << ", ";
        }
    }
    return 0;
}