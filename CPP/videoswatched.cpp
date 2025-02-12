#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if(a.second!=b.second){
    return a.second< b.second;
    
    }else{
        return a.first<b.first;
    }
}

class Solution
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        vector<string> movies;
        int n = watchedVideos.size();
        vector<bool> visited(n, false);
        visited[id] = true;
        int i = 0;
        vector<int> currLevel;
        currLevel.push_back(id);
        while (i < level)
        {
            vector<int> nextLevel;
            for (auto j : currLevel)
            {
                for (auto k : friends[j])
                {
                    if (!visited[k])
                    {
                        nextLevel.push_back(k);
                        visited[k] = true;
                    }
                }
            }
            currLevel.clear();
            currLevel = nextLevel;
            i++;
        }
        unordered_map<string, int> movieWithFrequency;
        for (auto j : currLevel)
        {
            for (auto k : watchedVideos[j])
            {

                auto l = movieWithFrequency.find(k);
                if (l == movieWithFrequency.end())
                {
                    movieWithFrequency[k] = 1;
                }
                else
                {
                    l->second++;
                }
            }
        }
        vector<pair<string, int>> movieWithFrequencyVec;
        for (auto j : movieWithFrequency)
        {
            movieWithFrequencyVec.push_back({j.first, j.second});
        }
        sort(movieWithFrequencyVec.begin(), movieWithFrequencyVec.end(), cmp);
        for(auto j : movieWithFrequencyVec){
            movies.push_back(j.first);
        }
        return movies;
    }
};

int main()
{

    return 0;
}