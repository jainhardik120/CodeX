#include <bits/stdc++.h>
using namespace std;

class Solution {
    void printVector(vector<int> &nums){
         int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(nums[i]<=0 || nums[i]>n){
                nums[i] = n+1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(nums[i]!=n+1 || nums[i]!=(-1*(n+1))){
                int number = nums[i];
                if(number<0){
                    number*=-1;
                }
                if((number-1)>=0 && (number-1)<n){

                if(nums[number-1]>0){
                    nums[number-1]*=-1;
                }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};

int main()
{
    Solution sol;
    // vector<int> vec{1,2,3,9,4,10,6,8,9,10,1,3,-1,-10};
    vector<int> vec{3,4,-1,1};
    cout << sol.firstMissingPositive(vec);
    return 0;
}