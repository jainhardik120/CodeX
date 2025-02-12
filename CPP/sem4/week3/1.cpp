#include<iostream>
using namespace std;
void cubeRoot(int n, int left, int right, int &ans)
{
    if(left<=right)
    {
        int mid= (left+right)/2;
        int cube= mid*mid*mid;
        if(cube<=n)
        {
            ans= mid;
            cubeRoot(n, mid+1, right, ans);
        }
        else if(cube>n)
        {
            cubeRoot(n, left, mid-1, ans);
        }
    }
}
int main()
{
    for(int i=2; i<= 100; i++)
    {
        int ans= -1;
        cout<<" i :"<<i<<" ";
        cubeRoot(i, 0, i-1, ans);
        cout<<ans<<endl;
    }
}