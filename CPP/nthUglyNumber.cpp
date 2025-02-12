#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        ans.push_back(1);
        int m2 = 0;
        int m3 = 0;
        int m5 = 0;
        n--;
        while(n){
            int n2 = ans[m2]*2; 
            int n3 = ans[m3]*3; 
            int n5 = ans[m5]*5;
            int min = n2;
            if(min>n3){
                min = n3;
            }
            if(min>n5){
                min = n5;
            }
            ans.push_back(min);
            if(min==n2){
                m2++;
            }
            if(min==n3){
                m3++;
            }
            if(min==n5){
                m5++;
            }
            n--;
        }
        // for (int i = 0; i < ans.size(); i++)
        // {
        //     cout << ans[i] << " ";
        // }
        
        return ans[ans.size()-1];
    }
};

int main()
{
    Solution sol;
    sol.nthUglyNumber(1690);
    
    return 0;
}