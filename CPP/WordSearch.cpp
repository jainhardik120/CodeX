#include <bits/stdc++.h>
using namespace std;

vector<int> isAvailable(int j, int *visited, int r, int c)
{
    vector<int> available;
    bool top, left, right, bottom;
    top = true;
    left = true;
    right = true;
    bottom = true;
    if (j % c == 0)
    {
        left = false;
    }
    if ((j + 1) % c == 0)
    {
        right = false;
    }
    if (j < c)
    {
        top = false;
    }
    if (j >= ((r - 1) * c))
    {
        bottom = false;
    }
    if (top)
    {
        if (visited[j - c] == 0)
        {
            available.push_back(j - c);
        }

        if (left)
        {
            if (visited[j - c - 1] == 0)
            {
                available.push_back(j - c - 1);
            }
        }
        if (right)
        {
            if (visited[j - c + 1] == 0)
            {
                available.push_back(j - c + 1);
            }
        }
    }
    if (left)
    {
        if (visited[j - 1] == 0)
        {
            available.push_back(j - 1);
        }
    }
    if (right)
    {
        if (visited[j + 1] == 0)
        {
            available.push_back(j + 1);
        }
    }
    if (bottom)
    {
        if (visited[j + c] == 0)
        {
            available.push_back(j + c);
        }

        if (left)
        {
            if (visited[j + c - 1] == 0)
            {
                available.push_back(j + c - 1);
            }
        }
        if (right)
        {
            if (visited[j + c + 1] == 0)
            {
                available.push_back(j + c + 1);
            }
        }
    }
    return available;
}

bool mySearch(string s, char *matrix, int r, int c, int charToBeFound, int toStartAt, int *visited)
{
    if (charToBeFound == s.length())
    {
        return true;
    }
    if (charToBeFound == 0)
    {
        for (int i = 0; i < r * c; i++)
        {
            if (matrix[i] == s.at(0))
            {
                visited[i] = 1;
                bool found = mySearch(s, matrix, r, c, charToBeFound + 1, i, visited);
                if (found == false)
                {
                    visited[i] = 0;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
    else
    {
        vector<int> available = isAvailable(toStartAt, visited, r, c);
        bool flag = false;
        int itr = 0;
        while (!flag && itr < available.size())
        {
            if (matrix[available[itr]] == s.at(charToBeFound))
            {
                visited[available[itr]] = 1;
                bool found = mySearch(s, matrix, r, c, charToBeFound + 1, available[itr], visited);
                if (found == false)
                {
                    visited[available[itr]] = 0;
                }
                else
                {
                    flag = true;
                    return true;
                }
            }
            itr++;
        }
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    string *arr = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int r, c;
    cin >> r >> c;
    char *matrix = new char[r * c];
    for (int i = 0; i < r * c; i++)
    {
        cin >> matrix[i];
    }
    int *found = new int[n];
    for (int i = 0; i < n; i++)
    {
        found[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int *visited = new int[r * c];
        for (int j = 0; j < r * c; j++)
        {
            visited[j] = 0;
        }
        if (mySearch(arr[i], matrix, r, c, 0, 0, visited)==true){
            cout << arr[i] << "\n";
        }
    }
    return 0;
}