#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int count = 0;
        if((dividend>=0 && divisor>=0)){
            while(dividend>=divisor){
                if(count==INT_MAX){
                    return count;
                }
                count++;
                dividend-=divisor;
            }
        }else if((dividend<0 && divisor<0)){
            while(dividend<=divisor){
                if(count==INT_MAX){
                    return count;
                }
                count++;
                dividend-=divisor;
            }
        }else if(dividend>=0 && divisor<0){
            while(dividend+divisor>=0){
                if(count==INT_MIN){
                    return count;
                }
                count--;
                dividend+=divisor;
            }
        }else{
            while(dividend+divisor<=0){
                count--;
                if(count==INT_MIN){
                    return count;
                }
                dividend+=divisor;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    cout << sol.divide(9,3) << "\n";
    cout << sol.divide(-9,-3) << "\n";
    cout << sol.divide(10,-3) << "\n";
    cout << sol.divide(-10,3) << "\n";
    cout << sol.divide(0,3) << "\n";
    cout << sol.divide(0,-3) << "\n";
    return 0;
}