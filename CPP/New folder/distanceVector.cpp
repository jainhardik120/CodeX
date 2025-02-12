// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    int findIndex(vector<int> &arr, int x){
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int m = (s+e)/2;
            if(arr[m]==x){
                return m;
            }else if(arr[m] < x){
                s = m+1;
            }else{
                e = m-1;
            }
        }
        return -1;
    }
    int findLeftIndex(vector<int> &arr, int x){
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int m = (s+e)/2;
            if(arr[m]>=x && (m==0 || arr[m-1]<x)){
                return m-1;
            }else if(arr[m]>=x){
                e=m-1;
            }else{
                s = m+1;
            }
        }
        return e;
    }
    int findRightIndex(vector<int> &arr, int x){
        int s = 0;
        int e = arr.size()-1;
        int n = arr.size();
        while(s<=e){
            int m = (s+e)/2;
            if(arr[m]<=x && (m==n-1 || arr[m+1]>x)){
                return m+1;
            }else if(arr[m]>=x){
                e=m-1;
            }else{
                s = m+1;
            }
        }
        return s;
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> vec = {2,4,5,7,9,10};
    for(int i = 0; i <= 20; i++){
        cout << sol.findRightIndex(vec, i) << "\n";
    }
    return 0;
}