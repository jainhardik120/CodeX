#include <bits/stdc++.h>
using namespace std;

class Twitter
{
    unordered_map<int, unordered_set<int>> followers;
    vector<pair<int, int>> tweets;

public:
    Twitter()
    {
        followers = unordered_map<int, unordered_set<int>>();
        tweets = vector<pair<int, int>>();
    }

    void postTweet(int userId, int tweetId)
    {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        if (followers.find(userId) == followers.end())
        {
            followers[userId] = unordered_set<int>();
        }
        vector<int> ans;
        int itr = tweets.size() - 1;
        auto followed = followers[userId];
        while (ans.size() < 10 && itr > -1)
        {
            auto tweet = tweets[itr];
            if (tweet.first == userId || followed.find(tweet.first) != followed.end())
            {
                ans.push_back(tweet.second);
            }
            itr--;
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        if (followers.find(followerId) == followers.end())
        {
            followers[followerId] = unordered_set<int>();
        }
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followers.find(followerId) == followers.end())
        {
            followers[followerId] = unordered_set<int>();
        }
        followers[followerId].erase(followeeId);
    }
};

void printVector(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    cout << "Starting Program...\n";
    Twitter *obj = new Twitter();
    obj->postTweet(1, 5);
    auto posts = obj->getNewsFeed(1);
    printVector(posts);
    obj->follow(1, 2);
    obj->postTweet(2, 6);
    posts = obj->getNewsFeed(1);
    printVector(posts);
    obj->unfollow(1, 2);
    posts = obj->getNewsFeed(1);
    printVector(posts);
    return 0;
}