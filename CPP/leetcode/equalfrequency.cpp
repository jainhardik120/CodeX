#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool equalFrequency(string word)
    {
        vector<int> count = vector<int>(26, 0);
        for (int i = 0; i < word.size(); i++)
        {
            int c = word[i] - 'a';
            count[c]++;
        }
        int frequency = 0;
        bool isSubUsed = false;
        for (int i = 0; i < count.size(); i++)
        {
            int currFreq = count[i];
            if (currFreq != 0)
            {
                if (frequency == 0)
                {
                    frequency = currFreq;
                }
                else
                {
                    if (frequency == currFreq)
                    {
                        continue;
                    }
                    else
                    {
                        if ((frequency > currFreq) && (frequency - 1 == currFreq) && (!isSubUsed))
                        {
                            frequency--;
                            isSubUsed = true;
                        }
                        else if ((frequency < currFreq) && (frequency + 1 == currFreq) && (!isSubUsed))
                        {
                            isSubUsed = true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return (isSubUsed || frequency==1);
    }
};

int main()
{

    return 0;
}