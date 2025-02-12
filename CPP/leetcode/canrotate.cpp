#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for ( int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if(mat[i][j]!=target[i][j]){
                    goto next;
                }
            }
            
        }
        return true;
        next:
        for ( int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if(mat[i][j]!=target[j][n-i-1]){
                    goto next2;
                }
            }
            
        }
        return true;
        next2:
        for ( int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if(mat[i][j]!=target[n-i-1][n-j-1]){
                    goto next3;
                }
            }
            
        }
        return true;
        next3:
        for ( int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if(mat[i][j]!=target[n-j-1][i]){
                    return false;
                }
            }
            
        }
        return true;
    }
};

int main()
{

    return 0;
}