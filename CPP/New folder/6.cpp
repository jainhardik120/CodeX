#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &p)
{
    int i = 0;
    int mid = (p.size() - 1) / 2;
    int j = mid + 1;
    int h = p.size() - 1;
    vector<int> b;
    while (i <= mid && j <= h)
    {
        if (p[i] < p[j])

        {
            b.push_back(p[i++]);
        }
        else
        {
            b.push_back(p[j++]);
        }
    }
    for (; i <= mid; i++)
    {
        b.push_back(p[i]);
    }
    for (; j <= h; j++)
    {
        b.push_back(p[j]);
    }
    return b;
}
int main()
{
    vector<int> vec = {-4, 6, 9, -1, 3};
    vec = merge(vec);
    cout << "Final result: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}