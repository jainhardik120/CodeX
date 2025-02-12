#include <bits/stdc++.h>
using namespace std;

int minimumProduct(int *arr, int n){
    int countNeg = 0, countZero = 0, maxNegative = INT_MIN, minPositive = INT_MAX;
    int product = 1;

    for (int i = 0; i < n; i++)
    {
        
        if(arr[i]==0){
            countZero++;
            continue;
        }
        if(arr[i]<0){
            countNeg++;
            if(arr[i]>maxNegative){
                maxNegative=arr[i];
            }
        }
        if(arr[i]>0){
            if(arr[i]<minPositive){
                minPositive = arr[i];
            }
        }
        product *= arr[i];
    }
    if(countZero==n || (countNeg==0&&countZero>0)){
        return 0;
    }
    if(countNeg==0){
        return minPositive;
    }
    if(((countNeg%2)==0)&&countNeg!=0){
        return product/maxNegative;
    }
    return product;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minimumProduct(arr, n);
    return 0;
}