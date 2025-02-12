#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0]!=b[0]){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}

class Solution {
    void update(vector<int> &bit, int n, int x){
        for(; x <= n; x += x&-x)
            bit[x]++;
    }
    int findSum(vector<int> &bit, int x){
        int sum = 0;
        for(; x > 0; x -= x&-x)
            sum += bit[x];
        return sum;
    }
    int findIndex(vector<int> &bit, int i){
        int x = i;
        int n = bit.size()-1;
        while(i<n){
            int s = findSum(bit, i+1);
            cout << i << " " << s << " ";
            if(i-s==x){
                return i;
            }else{
                i=x+s;
            }
        }
        return 0;
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<int> bit(n+1, 0);
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> sorted(n);
        int lastHeight = 0;
        int countLast = 0;
        for(int i = 0; i < n; i++){
            cout << "\n" << i << " ";
            cout << people[i][0] << " " << people[i][1];
            if(people[i][0]==lastHeight){
                countLast++;
            }else{
                lastHeight = people[i][0];
                countLast = 0;
            }
            int toSkipPlaces = people[i][1] - countLast;
            cout << " " << toSkipPlaces << " ";
            int j = findIndex(bit, toSkipPlaces);
            cout << j;
            sorted[j] = people[i];
            update(bit, n, j+1);
        }
        return sorted;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    auto ans = sol.reconstructQueue(people);
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
        return 0;
}
