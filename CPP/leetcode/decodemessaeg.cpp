#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> map = vector<int>(26 ,-1);
        int itr = 0;
        for (int i = 0; (i < key.size() && itr<26); i++)
        {
            char ch = key[i];
            if(ch==' '){
                continue;
            }
            int c = ch-'a';
            if(map[c]==-1){
                map[c] = itr++;
            }else{
                continue;
            }
        }
        for (int i = 0; i < message.size(); i++)
        {
            if(message[i]==' '){
                continue;
            }
            message[i] = map[message[i]-'a']+'a';
        }
        
        return message;
    }
};

int main()
{
    Solution sol;
    cout << sol.decodeMessage("the quick brown fox jumps over the lazy dog","vkbs bs t suepuv");
    return 0;
}