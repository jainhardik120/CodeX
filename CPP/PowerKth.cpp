#include <bits/stdc++.h>
using namespace std;

bool comparePowers(pair<int, int> first, pair<int, int> second){
        if(first.second!=second.second){
            return (first.second < second.second);
        }else{
            return (first.first < second.first);
        }
    }

class Solution
{
    unordered_map<int, int> umap = {
        {1 , 0}
    };
    int getPower(int n){
        auto itr = umap.find(n);
        if(itr != umap.end()){
            return itr->second;
        }
        int nextInt;
        if(n%2==0){
            nextInt = n/2;
        }else{
            nextInt = (n*3)+1;
        }
        int power =  1 + getPower(nextInt);
        umap[n] = power;
        return power;
    }
    
public:
    
    int getKth(int lo, int hi, int k)
    {
        vector<pair<int, int>> powerVector;
        for (int i = lo; i <= hi; i++)
        {
            powerVector.push_back({i, getPower(i)});
        }
        sort(powerVector.begin(), powerVector.end(), comparePowers);
        return (powerVector[k-1].first);
    }
};

int main()
{
    Solution sol;
    sol.getKth(10,15,2);
    return 0;
}