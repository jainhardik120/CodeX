#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        int *arr = new int[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 1; i < n; i++)
        {
            int currChar = s[i]-'0';
            int prevChar = s[i-1]-'0';
            bool isCurrPositionValid = (currChar!=0);
            bool isCombinedPositionValid;
            int totalNum = prevChar*10 + currChar;
            if(totalNum<=26 && totalNum>=10){
                isCombinedPositionValid = true;
            }
            int sum = 0;
            if(isCurrPositionValid){
                sum+=(1+arr[i]);
            }
            if(isCombinedPositionValid){
                sum+=(1+arr[i-1]);
            }
            arr[i+1] = sum;
        }
        return arr[n];
    }
};

int main()
{
    Solution sol;

    return 0;
}