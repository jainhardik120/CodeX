#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits;
        while(n){
            bits.push_back(n%2);
            n/=2;
        }      
        uint32_t ans = 0;
        for (int i = 0; i < bits.size(); i++)
        {
            ans*=2;
            ans+=bits[i];
        }
        for (int i = 0; i < 32-bits.size(); i++)
        {
            ans*=2;
        }
        
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.reverseBits(6);
    return 0;
}