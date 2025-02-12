// #include <bits/stdc++.h>
// using namespace std;

// bool check(int x, int y)
// {
//     return (x == 1 && y == 1);
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         char *arr = new char[n];
//         cin >> arr;
//         int x = 0, y = 0;
//         bool flag = false;
//         for (int i = 0; i < n; i++)
//         {
//             switch (arr[i])
//             {
//             case 'U':
//                 y++;
//                 break;
//             case 'D':
//                 y--;
//                 break;
//             case 'L':
//                 x--;
//                 break;
//             case 'R':
//                 x++;
//                 break;
//             default:
//                 break;
//             }
//             if (!flag)
//             {
//                 flag = check(x, y);
//             }
//         }
//         if(flag){
//             cout << "YES\n";
//         } else {
//             cout << "NO\n";
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
        char *arr = new char[n];
        if(n){
            cin >> arr;
        }
        int length = n;
        bool flag = false;
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            if (arr[i] == '1' && arr[n - i - 1] == '0')
            {
                length -= 2;
            }
            else if (arr[i] == '0' && arr[n - i - 1] == '1')
            {
                length -= 2;
            }
            else
            {
                if (!flag)
                {
                    cout << length << "\n";
                    flag=true;
                }
            }
        }
        if(!flag){
            cout << "0\n";
        }
        delete[] arr;
    }
    return 0;
}