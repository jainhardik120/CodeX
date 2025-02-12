#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int i = 0;
        int j = 1;
        if(n==0){
            return i;
        }
        if(n==1){
            return j;
        }
        n--;
        while(n--){
            int temp = j;
            j = i+j;
            i = temp;
        }
        return j;
    }
};

int main()
{
    Solution sol;
    cout << sol.fib(0);
    cout << sol.fib(1);
    cout << sol.fib(2);
    cout << sol.fib(3);
    cout << sol.fib(4);
    cout << sol.fib(5);
    return 0;
}