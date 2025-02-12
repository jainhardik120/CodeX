#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0.0)
        {
            return 0.0;
        }
        if (n == 0)
        {
            return 1.0;
        }
        long positiveN = abs(n);
        long copy = positiveN;
        queue<long> binary;
        long powerOf2 = 1;
        while (copy)
        {
            if (copy % 2 == 1)
            {
                binary.push(powerOf2);
            }
            copy /= 2;
            powerOf2 *= 2;
        }
        double result = 1.0;
        double currPow = x;
        long pow = 1;
        while (!binary.empty())
        {
            long top = binary.front();
            if (top == pow)
            {
                result *= currPow;
                binary.pop();
            }
            pow *= 2;
            currPow *= currPow;
        }
        if (n < 0)
        {
            return 1 / result;
        }
        else
        {
            return result;
        }
    }
};

int main()
{
    Solution sol;
    sol.myPow(-1.0, INT_MIN);
    return 0;
}