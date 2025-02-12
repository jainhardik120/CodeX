#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;
        int shouldBy1 = m % k;
        int fancy = 0;
        if (shouldBy1 <= a1)
        {
            a1 -= shouldBy1;
            m -= shouldBy1;
        }
        else
        {
            a1 = 0;
            fancy += (shouldBy1 - a1);
            m -= shouldBy1;
        }
        if (m <= (ak * k))
        {
            cout << fancy << "\n";
            continue;
        }
        else
        {
            m -= (ak * k);
            ak = 0;
        }
        int byA1 = a1 / k;
        if (m <= (byA1 * k))
        {
            cout << fancy << "\n";
            continue;
        }
        else
        {
            m -= (byA1 * k);
            a1 -= (byA1 * k);
        }
        if (m >= 0)
        {
            fancy+=(m/k);
        }
        cout << fancy << "\n";
    }
    return 0;
}