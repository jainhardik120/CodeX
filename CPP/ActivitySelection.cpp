#include <bits/stdc++.h>
using namespace std;

void maxActivities(int *start, int *finish, int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(finish[j]>finish[j+1]){
                int temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;
                temp = start[j+1];
                start[j+1] = start[j];
                start[j] = temp;
            }
        }
        
    }
    int lastFinish = -1;
    int itr = 0;
    int count = 0;
    while(itr<n){
        if(lastFinish<=start[itr]){
            count++;
            if(count!=1){
                cout << " | ";
            }
            cout << "[" << start[itr] << ", " << finish[itr] << "]";
            lastFinish = finish[itr];
        }
        itr++;
    }
}

int main()
{
    int start[6] = {1,3,0,5,8,5};
    int finish[6] = {2,4,6,7,9,9};
    maxActivities(start, finish, 6);
    return 0;
}