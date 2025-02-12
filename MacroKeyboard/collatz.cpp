#include <bits/stdc++.h>
using namespace std;

bool isValid[100000000] = {false};

bool collatzRecursive(int j)
{
    if(isValid[j]==true){
        return true;
    }
    if (j == 1)
    {
        isValid[j] = true;
        cout << 1 << "\n";
        return true;
    }
    cout << j << " ";
    int n;
    if (j % 2 == 0)
    {
        n = j / 2;
    }
    else
    {
        n = 3 * j + 1;
    }
    bool ans = collatzRecursive(n);
    isValid[j] = ans;
    return ans;
}


int main()
{
    
    return 0;
}