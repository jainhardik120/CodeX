#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> dpArray(n, false);
        dpArray[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
        {
            bool couldJump = false;
            int index = i+1;
            while(!couldJump && index <= (i+nums[i])){
                if(dpArray[index]){
                    couldJump = true;
                }
                index++;
            }
            dpArray[i] = couldJump;
        }
        return dpArray[0];
    }
};

int main()
{

    return 0;
}