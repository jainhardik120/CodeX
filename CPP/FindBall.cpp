#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> solutionGrid(m, vector<int>(n));
        for (int i = m-1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {

                if(i==m-1){
                    if(grid[i][j]==-1){
                        if(j!=0){
                            if(grid[i][j-1]==-1){
                                solutionGrid[i][j]=j-1;
                            }else{
                                solutionGrid[i][j]=-1;
                            }
                        }else{
                            solutionGrid[i][j]=-1;
                        }
                    }else{
                        if(j!=n-1){
                            if(grid[i][j+1]==1){
                                solutionGrid[i][j]=j+1;
                            }else{
                                solutionGrid[i][j]=-1;
                            }
                        }else{
                            solutionGrid[i][j]=-1;
                        }
                    }
                }else{
                    if(grid[i][j]==-1){
                        if(j!=0){
                            if(grid[i][j-1]==-1){
                                solutionGrid[i][j]=solutionGrid[i+1][j-1];
                            }else{
                                solutionGrid[i][j]=-1;
                            }
                        }else{
                            solutionGrid[i][j]=-1;
                        }
                    }else{
                        if(j!=n-1){
                            if(grid[i][j+1]==1){
                                solutionGrid[i][j]=solutionGrid[i+1][j+1];
                            }else{
                                solutionGrid[i][j]=-1;
                            }
                        }else{
                            solutionGrid[i][j]=-1;
                        }
                    }
                }
            }   
        }
        return solutionGrid[0];
    }
};

int main()
{

    return 0;
}