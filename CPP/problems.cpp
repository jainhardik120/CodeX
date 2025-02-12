#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        int sum = 0;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum+=arr[i];
            if (i > 0)
            {
                q.push({abs(arr[i] - arr[i - 1]), i});
            }
        }
        while (!q.empty() && k--)
        {
            pair<int, int> top = q.top();
            q.pop();
            if (abs(arr[top.second] - arr[top.second - 1]) != top.first)
            {
                k++;
                continue;
            }
            int i = top.second-1;
            int j = top.second;
            sum-=abs(arr[i]-arr[j]);
            if(arr[i]>arr[j]){
                arr[i] = arr[j];
                if(i!=0)
                    q.push({abs(arr[i] - arr[i - 1]),i});
            }else{
                arr[j] = arr[i];
                if(j!=n-1)
                    q.push({abs(arr[j] - arr[j+1]),j+1});
            }
        }
        cout << sum << "\n";
    }
}