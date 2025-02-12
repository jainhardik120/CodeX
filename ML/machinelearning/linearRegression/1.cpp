#include <iostream>
using namespace std;

int main()
{
    float int_rate = 0.066;
    float sum = 0.0;
    for (int i = 1; i <= 60; i++)
    {
        sum = sum + 500.00;
         sum = sum + (sum*int_rate)/12;
    }
    
    cout << sum << endl;
    return 0;
}