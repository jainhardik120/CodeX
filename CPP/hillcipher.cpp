#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findInverse(const vector<vector<int>>& keyMatrix) {
    int n = keyMatrix.size();
    
    // Create an augmented matrix [keyMatrix | I]
    vector<vector<int>> augmentedMatrix(n, vector<int>(2 * n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmentedMatrix[i][j] = keyMatrix[i][j];
            augmentedMatrix[i][j + n] = (i == j) ? 1 : 0;
        }
    }

    // Apply Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Make the diagonal element 1
        int divisor = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmentedMatrix[i][j] /= divisor;
        }

        // Make other rows' ith column element 0
        for (int j = 0; j < n; j++) {
            if (j != i) {
                int factor = augmentedMatrix[j][i];
                for (int k = 0; k < 2 * n; k++) {
                    augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    vector<vector<int>> inverseMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverseMatrix[i][j] = augmentedMatrix[i][j + n];
        }
    }

    return inverseMatrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

string decrypt(string key, string text)
{
    int n = text.size();
    if (key.size() != n * n)
    {
        return NULL;
    }
    vector<vector<int>> keyMatrix(n, vector<int>(n));
    int itr = 0;
    while (itr < n * n)
    {
        int i = itr / n;
        int j = itr % n;
        keyMatrix[i][j] = key[itr] - 'a';
        itr++;
    }
    printMatrix(findInverse(keyMatrix));
}

string encrypt(string key, string text)
{
    int n = text.size();
    if (key.size() != n * n)
    {
        return NULL;
    }
    vector<vector<int>> keyMatrix(n, vector<int>(n));
    int itr = 0;
    while (itr < n * n)
    {
        int i = itr / n;
        int j = itr % n;
        keyMatrix[i][j] = key[itr] - 'a';
        itr++;
    }
    string encrypted = "";
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += (keyMatrix[i][j] * (text[j] - 'a'));
        }
        sum %= 26;
        encrypted += (char)(sum + 'a');
    }
    return encrypted;
}

int main()
{
    string text;
    string key;
    cin >> text;
    cin >> key;
    // cout << encrypt(key, text);
    decrypt(key, text);
    return 0;
}