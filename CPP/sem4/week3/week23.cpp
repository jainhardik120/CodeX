#include <bits/stdc++.h>
using namespace std;

// void towerOfHanoi(char from, char to, char aux, int n){
//     if(n==0){
//         return;
//     }
//     towerOfHanoi(from, aux, to, n-1);
//     cout << "Move " << n << " from " << from << " to " << to << "\n";
//     towerOfHanoi(aux, to, from, n-1);
// }

// int fibonacci(int n){
//     if(n==1){
//         return 0;
//     } else if(n==2){
//         return 1;
//     } else {
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
// }

void algo1(int *arr, int a, int b){
    int n = b-a+1;
    if(n==2 && arr[a]>arr[a+1]){
        int temp = arr[a];
        arr[a] = arr[a+1];
        arr[a+1] = temp;
    }
    if(n>2){
        int m = ceil((2*n)/3.0);
        algo1(arr, a, a+m-1);
        algo1(arr, a+n-m, b);
        algo1(arr, a, a+m-1);
    }
}

void algo2(int *arr, int a, int b){
    int n = b-a+1;
    if(n==2 && arr[a]>arr[a+1]){
        int temp = arr[a];
        arr[a] = arr[a+1];
        arr[a+1] = temp;
    }
    if(n>2){
        int m = floor((2*n)/3.0);
        algo2(arr, a, a+m-1);
        algo2(arr, a+n-m, b);
        algo2(arr, a, a+m-1);
    }
}

int main()
{
    // towerOfHanoi('a', 'c', 'b', 3);
    // for (int i = 1; i < 10; i++)
    // {
    //     cout << fibonacci(i) << " ";
    // }
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    algo2(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}