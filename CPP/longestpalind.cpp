#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int findMaxLenUsingDp(vector<vector<int>> &dpArray, int n, string &s, int i, int j)
    {
        if (dpArray[i][j] != -2)
        {
            return dpArray[i][j];
        }
        if (i > j)
        {
            return dpArray[i][j] = -1;
        }
        if (i == j)
        {
            return dpArray[i][j] = 1;
        }
        if (s[i] != s[j])
        {
            return dpArray[i][j] = -1;
        }
        if (i == j - 1)
        {
            return dpArray[i][j] = 2;
        }
        int lenBetween = findMaxLenUsingDp(dpArray, n, s, i + 1, j - 1);
        if(lenBetween<0){
            return dpArray[i][j] = lenBetween;
        }else{
            return dpArray[i][j] = (lenBetween + 2);
        }
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<vector<int>> dpMatrix(n, vector<int>(n, -2));
        int maxLen = 0;
        int maxStart = 0;
        int maxEnd = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int len = findMaxLenUsingDp(dpMatrix, n, s, i, j);
                if (len > maxLen)
                {
                    maxStart = i;
                    maxEnd = j;
                    maxLen = len;
                }
            }
        }
        cout << maxStart << maxEnd << "\n";
        return s.substr(maxStart, (maxEnd-maxStart));
    }
};

int main()
{

    return 0;
}