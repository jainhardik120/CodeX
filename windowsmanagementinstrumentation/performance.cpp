#include <iostream>
#include <Windows.h>


ULONGLONG SubtractTimes(const FILETIME& ftA, const FILETIME& ftB) {
    ULARGE_INTEGER a, b;
    a.LowPart = ftA.dwLowDateTime;
    a.HighPart = ftA.dwHighDateTime;
    b.LowPart = ftB.dwLowDateTime;
    b.HighPart = ftB.dwHighDateTime;
    return a.QuadPart - b.QuadPart;
}


int main() {
    FILETIME idleTime, kernelTime, userTime;

    while (true) {
        // Get system times
        if (!GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
            std::cerr << "Failed to retrieve system times." << std::endl;
            return 1;
        }

        // Calculate CPU usage percentage
        ULONGLONG kernelTimeDiff = SubtractTimes(kernelTime, idleTime);
        ULONGLONG userTimeDiff = SubtractTimes(userTime);
        ULONGLONG totalTime = kernelTimeDiff + userTimeDiff;
        double cpuUsage = (totalTime - idleTimeDiff) * 100.0 / totalTime;

        std::cout << "CPU Usage: " << cpuUsage << "%" << std::endl;

        Sleep(1000);  // Sleep for 1 second
    }

    return 0;
}
