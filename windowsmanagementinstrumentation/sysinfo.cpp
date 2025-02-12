#include <bits/stdc++.h>
#include <sysinfoapi.h>
using namespace std;

#pragma comment (lib, "Kernel32.lib")

int main()
{
    LPSYSTEM_INFO sysInfo;
    GetSystemInfo(sysInfo);
    cout << sysInfo->dwNumberOfProcessors << endl;
    return 0;
}