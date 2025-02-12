#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPossible(vector<int> &wordLetters, vector<int> &letters)
    {
        for (int i = 0; i < 26; i++)
        {
            if (wordLetters[i] > letters[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<int> subtractVectors(vector<int> &wordLetters, vector<int> &letters)
    {
        vector<int> answer(26);
        for (int i = 0; i < 26; i++)
        {
            answer[i] = letters[i] - wordLetters[i];
        }
        return answer;
    }
    int scoreWords(vector<string> &words, int beginIndex, vector<int> &letters, vector<int> &score)
    {
        if (beginIndex >= words.size())
        {
            return 0;
        }
        vector<int> currWordLetters(26, 0);
        for (int i = 0; i < words[beginIndex].length(); i++)
        {
            currWordLetters[words[beginIndex][i] - 'a']++;
        }
        bool isWordPossible = isPossible(currWordLetters, letters);
        if (!isWordPossible)
        {
            cout << words[beginIndex] << " ";
            return scoreWords(words, beginIndex + 1, letters, score);
        }
        vector<int> remainingLetters = subtractVectors(currWordLetters, letters);
        int scoreIncludingWord = score[beginIndex] + scoreWords(words, beginIndex + 1, remainingLetters, score);
        int scoreWithoutWord = scoreWords(words, beginIndex + 1, letters, score);
        return max(scoreIncludingWord, scoreWithoutWord);
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        vector<int> myLetters(26, 0);
        for (int i = 0; i < letters.size(); i++)
        {
            myLetters[letters[i]-'a']++;
        }
        int numOfWords = words.size();
        vector<int> myScores(numOfWords,0);
        for (int i = 0; i < numOfWords; i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                myScores[i]+=score[words[i][j]-'a'];
            }
            
        }
        for (int i = 0; i < numOfWords; i++)
        {
            cout << myScores[i] << " ";
        }
        
        return scoreWords(words, 0, myLetters, myScores);
    }
};

int main()
{
    Solution sol;
    vector<string> words{
        "dog","cat","dad","good"
    };
    vector<int> scores{1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    vector<char> letters{'a','a','c','d','d','d','g','o','o'};
    cout << sol.maxScoreWords(words, letters, scores);
    return 0;
}