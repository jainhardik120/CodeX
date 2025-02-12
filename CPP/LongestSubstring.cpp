#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        unordered_set<char> string_set;
        while(j < n){
            if(string_set.find(s[j])!=string_set.end()){
                while(i < n && s[i]!=s[j]){
                    string_set.erase(s[i]);
                    i++;
                }
                i++;
            }
            string_set.insert(s[j]);
            maxLen = max(maxLen, (j-i + 1));
            j++;
        }
        return maxLen;
    }
};

int main(){

    return 0;
}