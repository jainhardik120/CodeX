#include <bits/stdc++.h>
using namespace std;

/*

i
j
k
l

odd & (1+(3k)) => i+k+l
even & (1+3k) => i+j+l

odd => i+k
even => i+j


1 2 3 4 5 6 7 8 9 10
a d c b c d a d c b

0
1
2
3
4
5
6
7
8
9
10

*/

class Solution
{
    int returnState(int i, int j, int k, int l)
    {
        int ans = 0;
        if ((i + k + l) % 2 == 0)
        {
            ans += 8;
        }
        if ((i + j + l) % 2 == 0)
        {
            ans += 4;
        }
        if ((i + k) % 2 == 0)
        {
            ans += 2;
        }
        if ((i + j) % 2 == 0)
        {
            ans += 1;
        }
        return ans;
    }

public:
    int flipLights(int n, int presses)
    {
        int *arr = new int[16];
        for (int i = 0; i < 16; i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i <= presses; i++)
        {
            for (int j = 0; j <= (presses-i); j++)
            {
                for (int k = 0; k <= (presses-(i+j)); k++)
                {
                    for (int l = 0; l <= (presses-(i+j+k)); l++)
                    {
                        if((i+j+k+l)==presses){
                            arr[returnState(i, j, k, l)] = 1;
                        }
                    }
                }
            }
        }

        if (n >= 4)
        {
            int count = 0;
            for (int i = 0; i < 16; i++)
            {
                if (arr[i] == 1)
                {
                    count++;
                }
            }
            return count;
        }
        if (n == 3)
        {
            int reqStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 0; i < 16; i++)
            {
                if (arr[i] == 1)
                {
                    int num = arr[i];
                    reqStates[(i / 8) * 4 + ((i / 2) % 2) * 2 + ((i) % 2) * 1] = 1;
                }
            }
            int count = 0;
            for (int i = 0; i < 8; i++)
            {
                if (reqStates[i] == 1)
                {
                    count++;
                }
            }
            return count;
        }
        if (n == 2)
        {
            int reqStates[] = {0, 0, 0, 0};
            for (int i = 0; i < 16; i++)
            {
                if (arr[i] == 1)
                {
                    int num = arr[i];
                    reqStates[(i / 8) * 2 + ((i) % 2) * 1] = 1;
                }
            }
            int count = 0;
            for (int i = 0; i < 4; i++)
            {
                if (reqStates[i] == 1)
                {
                    count++;
                }
            }
            return count;
        }
        if (n == 1)
        {
            int reqStates[] = {0, 0};
            for (int i = 0; i < 16; i++)
            {
                if (arr[i] == 1)
                {
                    reqStates[(i / 8)] = 1;
                }
            }
            int count = 0;
            for (int i = 0; i < 2; i++)
            {
                if (reqStates[i] == 1)
                {
                    count++;
                }
            }
            return count;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    cout << sol.flipLights(3, 10) << endl;
    return 0;
}