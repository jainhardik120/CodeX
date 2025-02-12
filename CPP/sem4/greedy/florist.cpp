#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getMinimumCost function below.
int getMinimumCost(int k, int* c, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(c[j] > c[j+1]){
                int temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp; 
            }
        }
    }
    int cost = 0;
    for (int i = n-1; i >=0; i--) {
        cout << c[i] << " ";
        int j = n - i-1;
        cout << j << " ";
        int x = j/k;
        cost += (x+1)*(c[i]);
        cout << "\n";
    }
    return cost;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int* c = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    cout << getMinimumCost(k, c, n);
    
    return 0;
}
