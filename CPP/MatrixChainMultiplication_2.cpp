#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        cin >> arr[i];
    }

    int **answer = new int *[n];
    for (int i = 0; i < n; i++)
    {
        answer[i] = new int[n];
    }

    for (int i = n-1; i >-1 ; i--)
    {
        for (int j = n-1; j > -1; j--)
        {
            
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            int x = j;
            int y = i + j + 1;
            if (y < x)
            {
                answer[x][y] = -1;
            }
            else if (x == j)
            {
                answer[x][y] = 0;
            }
            else
            {
                int currAnswer = INT_MAX;
                for (int k = x; k < y; k++)
                {
                    int mi =arr[x];
                    int mj =arr[k+1];
                    int nj =arr[y+1];
                    int temp = answer[x][k] + answer[k+1][y] + (mi*mj*nj);
                    if(temp<currAnswer){
                        currAnswer=temp;
                    }
                }
                
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}