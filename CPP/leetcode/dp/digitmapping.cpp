#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<char>> charMap = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> letterCombinationsWithIndex(string digits, int begin)
    {
        vector<string> answer;
        if(digits.length()==0){
            return answer;
        }
        if (begin == digits.length())
        {
            answer.push_back("");
            return answer;
        }
        vector<string> forwardAnswer = letterCombinationsWithIndex(digits, begin + 1);
        for (int i = 0; i < forwardAnswer.size(); i++)
        {
            vector<char> currMap = charMap[digits[begin]-'2'];
            for (int j = 0; j < currMap.size(); j++)
            {
                string temp = currMap[j] + forwardAnswer[i];
                answer.push_back(temp);
            }
        }
        return answer;
    }

public:
    vector<string> letterCombinations(string digits)
    {
        return letterCombinationsWithIndex(digits, 0);
    }
};

int main()
{

    return 0;
}