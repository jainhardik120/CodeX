#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int leastCommonMultiple = p;
        while(leastCommonMultiple%q!=0){
            leastCommonMultiple+=p;
        }
        int horizontal = leastCommonMultiple/q;
        int vertical = leastCommonMultiple/p;
        int ans[][2] = {{-1,0},{2,1}};
        return ans[(vertical%2)][(horizontal%2)];
    }
};

int main()
{

    return 0;
}