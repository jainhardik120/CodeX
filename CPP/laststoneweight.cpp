#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() >= 2)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int x = abs(a-b);
            if(x>0){
                q.push(x);
            }
        }
        if(q.empty()){
            return 0;
        }else{
            return q.top();
        }
    }
};

int main()
{

    return 0;
}