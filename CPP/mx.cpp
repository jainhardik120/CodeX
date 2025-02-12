#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void dfs(int s, int n, int currOr, int currXor, vector<int> &arr, int &minAns){
    if(s==n){
        minAns = min(minAns, currXor^currOr);
        return;
    }
    dfs(s+1, n, currOr | arr[s], currXor, arr, minAns);
    dfs(s+1, n, arr[s], currXor^currOr, arr, minAns);
}

int minXorOr(vector<int> &arr)
{
    int n = arr.size();
    int minAns = INT_MAX;
    dfs(0,n,0,0,arr,minAns);
    return minAns;
}

int main()
{
    vector<int> arr = {7,7,7};
    int min_xor = minXorOr(arr);
    cout << "Minimum XOR of OR values: " << min_xor << endl;
    return 0;
}
