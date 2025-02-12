#include <bits/stdc++.h>
#include<fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("2023EVESEM.pdf", ios::in | ios::binary);
    char ch;
    while (ch = file.get())
    {
        cout << ch << "\n";
    }
    file.close();
    return 0;
}