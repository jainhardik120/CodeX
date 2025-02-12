// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // int n, k;
//     // cin >> n >> k;
//     // int freeMins = 240-k;
//     // int nextQuestion = 5;
//     // int questionsDone = 0;
//     // while(freeMins>=nextQuestion && questionsDone < n){
//     //     questionsDone++;
//     //     freeMins-=nextQuestion;
//     //     nextQuestion+=5;
//     // }
//     // cout << questionsDone << "\n";

//     unsigned long long int n,m,a;
//     cin >> n >> m >> a;
//     unsigned long long int l,b;
//     if(n%a==0){
//         l = n/a;
//     } else {
//         l = (n/a) + 1;
//     }
//     if(m%a==0){
//         b = m/a;
//     } else {
//         b = (m/a) + 1;
//     }
//     cout << (l*b) << "\n";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        long long int a, b, n, m;
        cin >> a >> b >> n >> m;
        long long int effectiveCostA = (a*m)/(m+1);
        long long int coins = 0;
        if(effectiveCostA < b){
            long long int leftOver = n%(m+1);
            coins += (n/(m+1))*m*a;
            if(a<b){
                coins+= leftOver*a;
            } else {
                coins+=leftOver*b;
            }
            cout << coins << "\n";
        } else {
            cout << (n*b) << "\n";
        }
    }
    return 0;
}