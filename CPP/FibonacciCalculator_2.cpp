#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n==1){
        return 0;
    } else if(n==2){
        return 1;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main()
{
    for (int i = 1; i < 10000000; i++)
    {
        cout << fibonacci(i) << " ";
    }
    
    return 0;
}