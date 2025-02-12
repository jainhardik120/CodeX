// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     cout << q.front() << " ";
//     q.pop();
//     cout << q.front() << " ";
//     q.pop();
//     cout << q.front() << " ";
//     q.pop();
//     cout << q.front() << " ";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int minimumSum(int num) {
//         int arr[4] = {num/1000, (num/100)%10, (num/10)%10, num%10};
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3-i; j++)
//             {
//                 if(arr[j]>arr[j+1]){
//                     int temp = arr[j+1];
//                     arr[j+1] = arr[j];
//                     arr[j] = temp;
//                 }
//             }
//         }
//         return ((arr[0]*10 + arr[1]*10)+(arr[2]+arr[3]));
//     }
// };

// class Solution {
// public:
//     int maximizeSum(vector<int>& nums, int k) {
//         int max = nums[0];
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if(max<nums[i]){
//                 max=nums[i];
//             }
//         }
//         return ((max*k)+((k*(k-1))/2));
//     }
// };

// size 9, i = 3,

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxArea = 0;
//         int size = height.size();
//         for (int i = 0; i < height.size(); i++)
//         {
//             for (int j = 0; j < i; j++)
//             {
//                 if(height[j]>=height[i]){
//                     int area = height[i]*(i-j);
//                     if(area>maxArea){
//                         maxArea = area;
//                     }
//                     j=i;
//                 }
//             }
//             for (int j = size-1; j > i; j--)
//             {
//                 if(height[j]>=height[i]){
//                     int area = height[i]*(j-i);
//                     if(area>maxArea){
//                         maxArea = area;
//                     }
//                     j=i;
//                 }
//             }
//         }
//         return maxArea;
//     }
// };

class Solution
{
    bool *isDone;
public:
    int getKth(int lo, int hi, int k)
    {
        isDone = new bool[hi-lo+1];
        for (int i = 0; i < hi-lo+1; i++)
        {
            isDone[i] = false;
        }
        vector<int> ans;
        vector<uint32_t> currLevel = {1};
        vector<uint32_t> nextLevel;
        while (ans.size()<k)
        {
            for (int i = 0; i < currLevel.size(); i++)
            {
                cout << currLevel[i] << " ";
            }
            cout << "\n";
            sort(currLevel.begin(), currLevel.end());
            for (int i = 0; i < currLevel.size(); i++)
            {
                int n = currLevel[i];
                if(n>=lo && n<=hi){
                    if(!isDone[n-lo]){
                        isDone[n-lo] = true;
                        ans.push_back(n);
                        if(ans.size()==k){
                            delete[] isDone;
                            return n;
                        }
                    }
                }
            }
            for (int i = 0; i < currLevel.size(); i++)
            {
                int num = currLevel[i];
                if(num<126000){
                    nextLevel.push_back(num * 2);
                }
                if ((num - 1) % 3 == 0 && (num - 1) > 0 && (num-1)%2==1)
                {
                    nextLevel.push_back((num - 1) / 3);
                }
            }
            currLevel = nextLevel;
            nextLevel.clear();
        }
        delete[] isDone;
        return -1;
    }
};

int main()
{
    Solution sol;
    cout << sol.getKth(1,1000,777);
    return 0;
}