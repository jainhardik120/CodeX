// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int *arr = new int[n];
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//             if (arr[i] == 2)
//             {
//                 count++;
//             }
//         }
//         if (count == 0)
//         {
//             cout << "1\n";
//         }
//         else if (count % 2 == 1)
//         {
//             cout << "-1\n";
//         }
//         else
//         {
//             int count2 = 0;
//             int itr = 0;
//             while (count2 != (count / 2))
//             {
//                 if (arr[itr] == 2)
//                 {
//                     count2++;
//                 }
//                 itr++;
//             }
//             cout << itr << "\n";
//         }
//         delete[] arr;
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n%2==0){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int x = (n+1)/2;
            for (int i = 1; i <= x; i++)
            {
                cout << (2*i)-1 << " " << (3*x)-i << "\n";
            }
            int y = n/2;
            for (int i = 0; i < y; i++)
            {
                cout << (2*(i+1)) << " " << (2*n)-i << "\n";
            }
            
        }
    }
    return 0;
}