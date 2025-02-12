#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> dpMap;
    int M = 1000000007;
    vector<vector<int>> movements = {
        {-2,-1},{-2,1},{-1,-2},{1,-2},{-1,2},{1,2},{2,-1},{2,1}
    };
    bool isMoveValid(int i, int j){
        if(i<0 || i>3 || j<0 || j>2){
            return false;
        }
        if(i==3 && (j==0 || j==2)){
            return false;
        }
        return true;
    }
    int calcIndex(int n, int i, int j){
        return (((i*3)+((j==1)?1:0))*100000)+n;
    }
    int solve(int n, int i, int j){
        if(n==0){
            return 1;
        }
        if(dpMap.find(calcIndex(n,i,j))!=dpMap.end()){
            return dpMap[calcIndex(n,i,j)];
        }
        int answers = 0;
        for(auto move:movements){
            if(isMoveValid(i+move[0], j+move[1])){
                answers+=solve(n-1, i+move[0], j+move[1]);
                answers%=M;
            }
        }
        return dpMap[calcIndex(n,i,j)]=answers;
    }
public:
    int knightDialer(int n) {
        int answer = 0;
        for(int i = 0; i <= 3; i++){
            for(int j = 0; j <= 2; j++){
                if(isMoveValid(i,j)){
                    answer+=solve(n-1, i, j);
                    answer%=M;
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution sol;
    cout << sol.knightDialer(3131);
    return 0;
}