#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void primeSieve(int n)
{
    int *prime = new int[n];
    for (int i = 0; i < n; i++)
    {
        prime[i] = 0;
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
            cout << i << " ";
    }
}

void printPrime(int n){
    ofstream fout;
    fout.open("primes.txt");
    ofstream comp;
    comp.open("composites.txt");
    int count = 0;
    unsigned long int lastNum = 2;
    while(count < n){
        bool flag = false;
        unsigned long int j = 2;
        while(j*j<lastNum && !flag){
            if(lastNum%j==0){
                comp << lastNum << "  " << j << "\n";
                flag = true;
            }
            j++;
        }
        if(!flag){
            count++;
            fout << count << " " << lastNum << "\n";
        }
        lastNum++;
    }
    comp.close();
    fout.close();
}

int main()
{
    // primeSieve(10000);
    printPrime(10000000);
    return 0;
}