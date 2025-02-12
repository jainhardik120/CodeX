#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string makeString(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            len += (words[i].length());
        }
        int remLen = maxWidth - len;
        if (n == 1)
        {
            string temp = words[0];
            for (int i = 0; i < remLen; i++)
            {
                temp += " ";
            }
            return temp;
        }
        else
        {
            int minLen = remLen / (n - 1);
            int exLen = (remLen) % (n - 1);
            string result = "";
            for (int i = 0; i < n; i++)
            {
                result += words[i];
                if (i != n - 1)
                {
                    for (int j = 0; j < minLen; j++)
                    {
                        result += " ";
                    }
                    if(i<exLen){
                        result+=" ";
                    }
                }
            }
            return result;
        }
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        vector<string> temp;
        int remainingWidth = maxWidth;
        int itr = 0;
        temp.push_back(words[itr]);
        remainingWidth -= (words[itr].length());
        itr++;
        while (itr < words.size())
        {
            int len = words[itr].length() + 1;
            if (remainingWidth >= len)
            {
                temp.push_back(words[itr]);
                remainingWidth -= len;
            }
            else
            {
                res.push_back(makeString(temp, maxWidth));
                temp.clear();
                remainingWidth = maxWidth;
                temp.push_back(words[itr]);
                remainingWidth -= (len - 1);
            }
            itr++;
        }
        if (!temp.empty())
        {
            string lastString = "";
            for (int i = 0; i < temp.size(); i++)
            {
                if (i != 0)
                {
                    lastString += " ";
                }
                lastString += temp[i];
            }
            int lenLeft = maxWidth - (lastString.length());
            for (int i = 0; i < lenLeft; i++)
            {
                lastString += " ";
            }
            res.push_back(lastString);
        }
        return res;
    }
};

int main()
{

    return 0;
}