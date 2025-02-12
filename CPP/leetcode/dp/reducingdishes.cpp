#include <bits/stdc++.h>
using namespace std;
/*

5 0 -1 -8 -9

5
10
14
10

newSatis = oldSatis + sum + currElement

*/
class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int currSatisfaction = 0;
        int currSum = 0;
        for (int i = 0; i < satisfaction.size(); i++)
        {
            int tempSatisfaction = currSatisfaction + currSum + satisfaction[i];
            if (tempSatisfaction <= currSatisfaction)
            {
                return currSatisfaction;
            }
            else
            {
                currSatisfaction = tempSatisfaction;
                currSum += satisfaction[i];
            }
        }
        return currSatisfaction;
    }
};

int main()
{

    return 0;
}