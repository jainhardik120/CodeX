#include <bits/stdc++.h>
using namespace std;

bool compare(pair<char, int> &a, pair<char, int> &b)
{
    return a.first < b.first;
}

string generateCipherText(string plainText, vector<vector<char>> &lookupTable)
{
    vector<pair<char, char>> mapOfIndices(26);
    string indices = "ADFGX";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mapOfIndices[lookupTable[i][j] - 'a'] = {indices[i], indices[j]};
        }
    }
    mapOfIndices['j' - 'a'] = mapOfIndices['i' - 'a'];
    string result = "";
    for (auto ch : plainText)
    {
        result += mapOfIndices[ch - 'a'].first;
        result += mapOfIndices[ch - 'a'].second;
    }
    return result;
}

string arrangeInOrder(string keyword, string ciphertext)
{
    vector<pair<char, int>> order;
    for (int i = 0; i < keyword.length(); i++)
    {
        order.push_back({keyword[i], i});
    }
    sort(order.begin(), order.end(), compare);
    string res = "";
    for (int i = 0; i < order.size(); i++)
    {
        int x = order[i].second;
        while (x < ciphertext.length())
        {
            res += ciphertext[x];
            x += keyword.size();
        }
    }
    return res;
}

vector<vector<char>> prepareLookupTable(string lookupkey)
{
    vector<vector<char>> lookupTable(5, vector<char>(5));
    for (int i = 0; i < 25; i++)
    {
        lookupTable[i / 5][i % 5] = lookupkey[i];
    }
    return lookupTable;
}

string encryption(string lookupKey, string keyword, string plaintext)
{
    vector<vector<char>> lookupTable = prepareLookupTable(lookupKey);
    string cipher = generateCipherText(plaintext, lookupTable);
    return arrangeInOrder(keyword, cipher);
}

int main()
{
    cout << encryption("phqgmeaynofdxkrcvszwbutil", "GERMAN", "attack");
    return 0;
}