#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans;
        ans.push_back(1);
        int x = primes.size();
        vector<int> indices(x, 0);
        n--;
        int i, minVal;
        vector<int> indicesToUpdate;
        while(n){
            minVal = 100000000;
            indicesToUpdate.clear();
            for(int j = 0; j < x; j++){
                i = primes[j]*ans[indices[j]];
                if (i < minVal){
                    minVal = i;
                    indicesToUpdate.clear();
                    indicesToUpdate.push_back(j);
                }else if(i==minVal){
                    indicesToUpdate.push_back(j);
                }
            }
            ans.push_back(minVal);
            for(int k : indicesToUpdate){
                indices[k]++;
            }
            n--;
        }
        for(i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        return ans[ans.size()-1];
    }
};
int main()
{
    Solution sol;
    vector<int> primes = {2,7,13,19};
    cout << sol.nthSuperUglyNumber(12, primes);
    return 0;
}