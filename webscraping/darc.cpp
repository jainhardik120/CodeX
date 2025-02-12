// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int* arr = new int[10];
//     for(int i = 0; i < 10; i++){
//         cin >> arr[i];
//     }
//     int leftSum = 0;
//     int leftMin = INT_MAX;
//     int rightSum = 0;
//     int rightMin = INT_MAX;
//     for(int i = 0; i < 5; i++){
//         leftSum+=arr[i];
//         leftMin = min(leftMin, arr[i]);
//     }
//     for(int i = 5; i < 10; i++){
//         rightSum+=arr[i];
//         rightMin = min(rightMin, arr[i]);
//     }
//     cout << max((rightSum-rightMin), (leftSum-leftMin)) << endl;
//     delete[] arr;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    int avg = sum/n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=avg){
            count++;
        }
    }
    cout << count << "\n";
    delete[] arr;
    return 0;
}