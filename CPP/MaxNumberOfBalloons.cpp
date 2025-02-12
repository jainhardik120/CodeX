#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int numEquivDominoPairs(vector<vector<int>> &dominoes)
//     {
//         unordered_map<int, int> freq;
//         int total = 0;
//         for (auto i : dominoes)
//         {
//             sort(i.begin(), i.end());
//             int index = (10 * i[0]) + (i[1]);
//             auto j = freq.find(index);
//             if (j == freq.end())
//             {
//                 freq[index] = 1;
//             }
//             else
//             {
//                 total+= j->second;
//                 freq[index]++;
//             }
//         }
//         return total;
//     }
// };

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        // balloon   b-1, a-1, l-2, o-2, n-1
        vector<int> freq(26, 0);
        for (auto i : text)
        {
            freq[i - 'a']++;
        }
        int max = freq[0];
        if (freq[1] < max)
        {
            max = freq[1];
        }
        if (freq['n'-'a']<max){
            max = freq['n'-'a'];
        }
        if((freq['o'-'a']/2)<max){
            max = freq['o'-'a']/2;
        }
        if((freq['l'-'a']/2)<max){
            max = freq['l'-'a']/2;
        }
        return max;
    }
};

int main()
{

    return 0;
}