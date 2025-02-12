#include <bits/stdc++.h>
using namespace std;

void printPattern(int n)
{
    ofstream fout;
    fout.open("pattern.txt");
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            if (i == n || j == n || i == j ||
                j == (2 * n - i) ||
                (i < n && j == 0) ||
                (i > n && j == 2 * n) ||
                (i == 0 && j > n) ||
                (i == 2 * n && j < n))
            {
                fout << "* ";
            }
            else
            {
                fout << "  ";
            }
        }
        fout << "\n";
    }
    fout.close();
}

int main()
{
    printPattern(50);
    return 0;
}