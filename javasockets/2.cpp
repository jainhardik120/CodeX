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
        char *str = new char[n + 1];
        cin >> str;
        int i = 0;
        char last = 'm';
        bool flag = true;
        while (i < n && flag)
        {
            int curr = str[i];
            if (curr == last || curr == last - 32 || curr == last + 32)
            {
                i++;
                last = curr;
            }
            else if ((last == 'm' || last == 'M') && (curr == 'e' || curr == 'E') ||
                     (last == 'e' || last == 'E') && (curr == 'o' || curr == 'O') ||
                     (last == 'o' || last == 'O') && (curr == 'w' || curr == 'W'))
            {
                i++;
                last = curr;
            }
            else
            {
                flag = false;
            }
        }
        if (flag == false)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
        delete[] str;
    }
    return 0;
}