#include <bits/stdc++.h>
using namespace std;

/*
1 0

*/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2 + (n%2); i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
    // void rotate(vector<vector<int>> &matrix)
    // {
    //     int n = matrix.size();
    //     for (int i = 0; i < n / 2; i++)
    //     {
    //         for (int j = 0; j < n / 2; j++)
    //         {
    //             int temp = matrix[i][j];
    //             matrix[i][j] = matrix[n - j - 1][i];
    //             matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
    //             matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
    //             matrix[j][n - i - 1] = temp;
    //         }
    //     }
    // }
};

int main()
{
    Solution sol;
    // vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 5;
    vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(n,0));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[i][j] = 10*i + j;
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    sol.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}