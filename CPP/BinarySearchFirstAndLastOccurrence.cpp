#include <bits/stdc++.h>
using namespace std;

void binarySearch(int *arr, int n, int key){
    int start = 0;
    int end = n-1;
    bool flag = false;
    int mid;
    while(start<=end && !flag){
        mid = start + (end-start)/2;
        if(arr[mid]==key){
            flag = true;
        } else if(arr[mid]>key){
            end = mid -1;
        } else if(arr[mid]<key){
            start = mid+1;
        }
    }
    if(!flag){
        cout << "Element not found in the array\n";
        return;
    }
    int x = mid;
    while(arr[x] == key){
        x--;
    }
    cout << "The first occurrence of element " << key << " is located at index " << (x+1) << "\n";
    x = mid;
    while(arr[x] == key){
        x++;
    }
    cout << "The last occurrence of element " << key << " is located at index " << (x-1) << "\n";
}

int main()
{
    int arr[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    for (int i = 1; i < 11; i++)
    {
        binarySearch(arr, sizeof(arr)/sizeof(int), i);
    }
    return 0;
}