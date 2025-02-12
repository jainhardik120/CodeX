// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int m = n;
//         int x1 = 1;
//         int x2 = 0;
//         int a1 = 0;
//         int a2 = 0;
//         int b1 = 0;
//         int b2 = 0;
//         int chance = true;
//         while(n){
//             if(chance){
//                 if((x1+x2)<=n){
//                     a1+=x1;
//                     a2+=x2;
//                     n-=(x1+x2);
//                 }else{
//                     if((m-n)%2==0){
//                         a1+=((n+1)/2);
//                         a2+=((n)/2);
//                     }else{
//                         a2+=((n+1)/2);
//                         a1+=((n)/2);
//                     }
//                     n=0;
//                 }
//                 x1++;
//                 x2+=3;
//             } else {
//                 if((x1+x2)<=n){
//                     b1+=x1;
//                     b2+=x2;
//                     n-=(x1+x2);
//                 }else{
//                     if((m-n)%2==0){
//                         b1+=((n+1)/2);
//                         b2+=((n)/2);
//                     }else{
//                         b2+=((n+1)/2);
//                         b1+=((n)/2);
//                     }
//                     n=0;
//                 }
//                 x1+=3;
//                 x2++;
//             }
//             chance = !chance;
//         }
//         cout << a1 << " " << a2 << " " << b1 << " " << b2 << "\n";
//     }
//     return 0;
// }

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
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         int operations = 0;
//         int i = 1;
//         bool done = false;
//         while (i <= n && !done)
//         {
//             bool flag = false;
//             int j = 0;
//             int max = 0;
//             while (!flag && j < n)
//             {
//                 if (arr[j] == i)
//                 {
//                     flag = true;
//                 }
//                 if (arr[j] > arr[max])
//                 {
//                     max = j;
//                 }
//                 j++;
//             }
//             if (arr[max] <= i)
//             {
//                 done = true;
//             }
//             if (!flag)
//             {
//                 operations += (arr[max] - i);
//                 arr[max] = i;
//             }
//             i++;
//         }
//         cout
//             << operations << "\n";
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
    while(t--){
        int n;
        cin >> n;
        char* arr = new char[3];
        int *arrW = new int[n];
        int *arrI = new int[n];
        int *arrN = new int[n];
        vector<int> i1;
        vector<int> i2;
        vector<char> c1;
        vector<char> c2;
        for (int i = 0; i < n; i++)
        {
            arrW[i] = 0;
            arrI[i] = 0;
            arrN[i] = 0;
            cin >> arr;
            for (int j = 0; j < 3; j++)
            {
                switch (arr[j])
                {
                case 'w':
                    arrW[i]++;
                    break;
                case 'i':
                    arrI[i]++;
                    break;
                case 'n':
                    arrN[i]++;
                    break;
                default:
                    break;
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arrW[i] << arrI[i] << arrN[i] << "\n";
        // }
        
        int operations = 0;
        for (int i = 0; i < n; i++)
        {
            if(arrW[i]==0){
                int j = i+1;
                bool flag = false;
                while(!flag && j < n){
                    if(arrW[j]>1){
                        if(arrI[i]>1){
                            arrI[i]--;
                            arrI[j]++;
                            arrW[j]--;
                            arrW[i]++;
                            i1.push_back(i);
                            i2.push_back(j);
                            c1.push_back('i');
                            c2.push_back('w');
                            operations++;
                            flag = true;
                        }else if(arrN[i]>1){
                            arrN[i]--;
                            arrN[j]++;
                            arrW[j]--;
                            arrW[i]++;
                            i1.push_back(i);
                            i2.push_back(j);
                            c1.push_back('n');
                            c2.push_back('w');
                            operations++;
                            flag = true;
                        }
                    }
                    j++;
                }
            }
            if(arrI[i]==0){
                int j = i+1;
                bool flag = false;
                while(!flag && j < n){
                    if(arrI[j]>1){
                        if(arrW[i]>1){
                            arrW[i]--;
                            arrW[j]++;
                            arrI[j]--;
                            arrI[i]++;
                            i1.push_back(i);
                            i2.push_back(j);
                            c1.push_back('w');
                            c2.push_back('i');
                            operations++;
                            flag = true;
                        }else if(arrN[i]>1){
                            arrN[i]--;
                            arrN[j]++;
                            arrI[j]--;
                            arrI[i]++;
                            i1.push_back(i);
                            i2.push_back(j);
                            c1.push_back('n');
                            c2.push_back('i');
                            operations++;
                            flag = true;
                        }
                    }
                    j++;
                }
            }
            if(arrN[i]==0){
                int j = i+1;
                bool flag = false;
                while(!flag && j < n){
                    if(arrN[j]>1){
                        if(arrI[i]>1){
                            arrI[i]--;
                            arrI[j]++;
                            arrN[j]--;
                            arrN[i]++;
                            i1.push_back(i);
                            i2.push_back(j);
                            c1.push_back('i');
                            c2.push_back('n');
                            operations++;
                            flag = true;
                        }else if(arrW[i]>1){
                            arrW[i]--;
                            arrW[j]++;
                            arrN[j]--;
                            arrN[i]++;
                            i1.push_back(i);
                            i2.push_back(j);
                            c1.push_back('w');
                            c2.push_back('n');
                            operations++;
                            flag = true;
                        }
                    }
                    j++;
                }
            }
        }
        cout << operations << "\n";
        for (int i = 0; i < operations; i++)
        {
            cout << i1[i] + 1 << " " << c1[i] << " " << i2[i]+1 << " "<< c2[i] << "\n";
        }
        i1.clear();
        i2.clear();
        c1.clear();
        c2.clear();
        delete[] arrW;
        delete[] arrI;
        delete[] arrN;
        delete[] arr;

        
    }
    return 0;
}