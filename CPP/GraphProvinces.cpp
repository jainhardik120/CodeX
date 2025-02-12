#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int start, int n){
        for (int i = 0; i < n; i++)
        {
            if(isConnected[start][i]==1 && !visited[i]){
                visited[i]=true;
                dfs(isConnected, visited, i, n);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numProvince = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if(!visited[i]){
                numProvince++;
                dfs(isConnected, visited, i, n);
            }
        }
        return numProvince;
    }
};

int main()
{

    return 0;
}