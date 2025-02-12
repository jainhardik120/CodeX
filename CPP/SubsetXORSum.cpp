#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> currXOR = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> nextXOR;
            for (int j = 0; j < currXOR.size(); j++)
            {
                nextXOR.push_back(currXOR[j]);
                nextXOR.push_back(currXOR[j]^nums[i]);
            }
            currXOR.clear();
            currXOR = nextXOR;
        }
        int sum = 0;
        for (int i = 0; i < currXOR.size(); i++)
        {
            sum += currXOR[i];
        }
        return sum;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {3,4,5,6,7,8};
    cout << sol.subsetXORSum(arr);
    return 0;
}