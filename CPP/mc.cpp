#include <bits/stdc++.h>
using namespace std;

#define MAX 3

struct state
{
    int miss;
    int cann;
    bool l;
    state(int a, int b, bool c) : miss(a), cann(b), l(c) {}
};


// a->cann b->miss
bool isStateValid(int a, int b)
{
    return ((a >= 0 && a <= MAX && b >= 0 && b <= MAX)) && !((b > 0 && a > b) || (MAX - b > 0 && (MAX - a) > (MAX - b)));
}

void displayState(state *& s){
    cout << s->miss << " " << s->cann << " " << ((s->l)?"Left":"Right") << "\n";
}

int main()
{
    vector<state> possibleStates;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            if (isStateValid(i, j))
            {
                possibleStates.push_back(state(j, i, true));
                possibleStates.push_back(state(j, i, false));
            }
        }
    }

    return 0;
}