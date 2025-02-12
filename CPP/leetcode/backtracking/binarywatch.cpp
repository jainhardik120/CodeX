#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<string> generateSols(vector<int> &arr, int currStep,int currOn, int turnedOn)
    {
        if(currStep>=10){
            vector<string> ans;
            return ans;
        }
        if (currOn == turnedOn)
        {
            vector<string> ans;
            int hour = ((arr[0] * 8) + (arr[1] * 4) + (arr[2] * 2) + (arr[3] * 1));
            int min = ((arr[4] * 32) + (arr[5] * 16) + (arr[6] * 8) + (arr[7] * 4) + (arr[8] * 2) + (arr[9] * 1));
            if (hour > 11)
            {
                return ans;
            }
            if (min > 59)
            {
                return ans;
            }
            if(hour==0 && min==0){
                return ans;
            }
            char time[6] = "";
            sprintf(time, "%d:%02d", hour, min);
            ans.push_back(time);
            return ans;
        }
        vector<string> str1;
        vector<string> str2;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                str2 = generateSols(arr, currStep+1,currOn, turnedOn);
                arr[i] = 1;
                for (int i = 0; i < str2.size(); i++)
                {
                    str1.push_back(str2[i]);
                }
                str2.clear();
                str2 = generateSols(arr, currStep + 1,currOn+1, turnedOn);
                arr[i] = 0;
                for (int i = 0; i < str2.size(); i++)
                {
                    str1.push_back(str2[i]);
                }
                str2.clear();
            }
        }
        return str1;
    }

    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<int> initialArr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        return generateSols(initialArr, 0,0, turnedOn);
    }
};

int main()
{
    Solution sol;
    vector<string> ans= sol.readBinaryWatch(1);
    cout << ans.size();
     for (int i = 0; i < ans.size(); i++)
                {
                    cout << ans[i] << endl;
                }
    return 0;
}