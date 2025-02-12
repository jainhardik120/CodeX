#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> sum = vector<int>(1001 ,0);
        for (int i = 0; i < citations.size(); i++)
        {
            sum[citations[i]]++;
        }
        if(sum[1000]>=1000){
            return 1000;
        }
        for (int i = 999; i > -1; i--)
        {
            sum[i] = sum[i]+sum[i+1];
            if(sum[i]>=i){
                return i;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> citations = {3,0,6,1,5};
    sol.hIndex(citations);
    return 0;
}