#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> q;
        for(auto i : nums){
            q.push(i);
        }
        int a = q.top();
        q.pop();
        int b= q.top();
        return ((a-1)*(b-1));
    }
};


int main()
{

    return 0;
}