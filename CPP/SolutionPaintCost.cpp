#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int time = 0;

        int prevRepeated = 0;
        char prevColor = ' ';
        int maxConsecutive = INT_MIN;
        int sumConsecutive = 0;
        for (int i = 0; i < colors.size(); i++)
        {
            if (prevColor != colors[i])
            {
                prevColor = colors[i];
                if (prevRepeated == 1)
                {
                    time += (sumConsecutive-maxConsecutive);
                }
                prevRepeated = 0;
                maxConsecutive = neededTime[i];
                sumConsecutive = neededTime[i];
            }
            else
            {
                prevRepeated = 1;
                sumConsecutive+=neededTime[i];
                maxConsecutive = (maxConsecutive < neededTime[i]) ? neededTime[i] : maxConsecutive;
            }
        }
        if(prevRepeated==1){
            time+=(sumConsecutive-maxConsecutive);
        }
        return time;
    }
};

int main()
{
    Solution sol;
    string colors = "aabaa";
    vector<int> neededTime = {1,2,3,4,1};
    cout << sol.minCost(colors, neededTime);
    return 0;
}