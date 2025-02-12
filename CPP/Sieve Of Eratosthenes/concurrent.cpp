#include <iostream>
#include <thread>
#include <fstream>
using namespace std;

void printPrime(int n, unsigned long int x){
    ofstream fout;
    // fout.open(x + ".txt");
    int count = 0;
    unsigned long int lastNum = x;
    while(count < n){
        bool flag = false;
        unsigned long int j = 2;
        while(j*j<lastNum && !flag){
            if(lastNum%j==0){
                flag = true;
            }
            j++;
        }
        if(!flag){
            count++;
            cout << count << " " << lastNum << "\n";
        }
        lastNum++;
    }
    // fout.close();
}

int main() {
    // int x = 3;
    // int y = 5;
    // std::thread t(print_sum, x, y);
    // t.join();
    for (int i = 0; i < 5; i++)
    {
        std::thread t(printPrime, 10, i*1000);
        t.join();
    }
    
}
