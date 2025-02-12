#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while (1)
        {
            if (sx == tx && sy == ty)
            {
                return true;
            }
            if (tx < sx || ty < sy)
            {
                return false;
            }
            if (tx > ty)
            {
                tx -= ty;
            }
            else if (ty > tx)
            {
                ty -= tx;
            }
            else
            {
                return false;
            }
        }
    }
};

int main()
{

    return 0;
}