#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int* ans = new int[n+1];
//         ans[0] = 0;
//         ans[1] = nums[0];
//         for(int i = 2; i < n+1; i++){
//             ans[i] = max(ans[i-2] + nums[i-1], ans[i-1]);
//         }
//         int ansToReturn = ans[n];
//         delete[] ans;
//         return ansToReturn;
//     }
// };
// class Solution {
// public:
//     int maximum69Number (int num) {
//         int max6 = -1;
//         int count = 0;
//         int originalNum = num;
//         while(num){
//             if(num%10==6){
//                 max6 = count;
//             }
//             count++;
//             num = num/10;
//         }
//         if(max6==-1){
//             return originalNum;
//         }else{
//             return originalNum + (3*pow(10, max6));
//         }
//     }
// };

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int ans  =-1;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> vec(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    vec[i][j] = 0;
                }
                else if (matrix[i - 1][j - 1] == '0')
                {
                    vec[i][j] = 0;
                }
                else
                {
                    vec[i][j] = 1 + min(min(vec[i - 1][j], vec[i][j - 1]), vec[i - 1][j - 1]);
                    if(ans<vec[i][j]){
                        ans=vec[i][j];
                    }
                }
            }
        }
        // for (int i = 0; i < m + 1; i++)
        // {
        //     for (int j = 0; j < n + 1; j++)
        //     {
        //         cout << vec[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return (ans*ans);
    }
};

int main()
{
    Solution sol;

    // vector<int> vec = vector<int>();
    // vec.push_back(2);
    // vec.push_back(7);
    // vec.push_back(9);
    // vec.push_back(3);
    // vec.push_back(1);
    // cout << sol.rob(vec);

    // cout << sol.maximum69Number(9669);

    vector<vector<char>> vect{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    sol.maximalSquare(vect);

    return 0;
}