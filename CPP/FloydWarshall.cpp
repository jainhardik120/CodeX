#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if(temp==-1){
                matrix[i][j] = 100;
            } else {
                matrix[i][j] = temp;
            }
        }
    }
    for (int x = 0; x < n; x++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = matrix[i][x] + matrix[x][j];
                if(matrix[i][j]>temp){
                    matrix[i][j] = temp;
                }
            }
            
        }
        cout << "A" << x << "\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
    
    return 0;
}