#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int m;
int n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific = vector<vector<bool>>(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic = vector<vector<bool>>(m, vector<bool>(n,false));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            dfs(0, i, pacific, heights);
            dfs(m-1, i, atlantic, heights);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, pacific, heights);
            dfs(i, n-1, atlantic, heights);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(atlantic[i][j]&&pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void dfs(int i, int j, vector<vector<bool>>& visited,vector<vector<int>>& heights){
        if(visited[i][j]){
            return;
        }
        visited[i][j] = true;
        if(i!=0 && heights[i][j]<=heights[i-1][j]){
            dfs(i-1, j, visited, heights);
        }
        if(i!=m-1 && heights[i][j]<=heights[i+1][j]){
            dfs(i+1, j, visited, heights);
        }
        if(j!=0 && heights[i][j]<=heights[i][j-1]){
            dfs(i, j-1, visited, heights);
        }
        if(j!=n-1 && heights[i][j]<=heights[i][j+1]){
            dfs(i, j+1, visited, heights);
        }
    }
};

int main()
{

    return 0;
}