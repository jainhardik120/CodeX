#include <bits/stdc++.h>
using namespace std;

void dfs(stack<pair<int, int>> myStack, int length, bool *visited)
{
    int n = 0;
    int length = 0;
    while (!myStack.empty())
    {
        if (length != 3)
        {
            pair<int, int> top = myStack.top();
            myStack.pop();
            n = ((10 * n) + top.first);
            length++;
            for (int i = 0; i < 3; i++)
            {
                if (!visited[i])
                {
                    pair<int, int> newPair = {i + 1, top.first};
                    myStack.push(newPair);
                }
            }
        }
    }
    cout << n;
}

int main()
{
    stack<pair<int, int>> myStack;

    bool visited[3] = {false, false, false};
    for (int i = 0; i < 3; i++)
    {
        if (!visited[i])
        {
            pair<int, int> newPair = {i + 1, 0};
            myStack.push(newPair);
        }
    }
    dfs(myStack, 0, visited);
    return 0;
}