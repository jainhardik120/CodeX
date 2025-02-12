#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        queue<pair<string, int>> q;
        q.push({"(", 1});
        while(!q.empty()){
            auto head = q.front();
            q.pop();
            if(head.second>0){
                string temp1= head.first + ")";
                if(temp1.length() != (n*2)){
                    q.push({temp1, head.second-1});
                }else{
                    res.push_back(temp1);
                }
            }
            if(((head.first.length() + head.second)/2) < n){
                string temp2= head.first + "(";
                if(temp2.length() != (n*2)){
                    q.push({temp2, head.second+1});
                }else{
                    res.push_back(temp2);
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}