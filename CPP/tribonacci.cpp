#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int x = 0;
        int y = 1;
        int z = 1;
        if(n==0){
            return x;
        }
        if(n==1){
            return y;
        }
        if(n==2){
            return z;
        }
        n-=2;
        while(n--){
            int temp = x+y+z;
             x = y;
             y = z;
             z = temp;
        }
        return z;
    }
};

int main(){
    Solution sol;
    for (int i = 0; i < 10; i++)
    {
        cout << sol.tribonacci(i) << "\n";
    }
    
    return 0;
}