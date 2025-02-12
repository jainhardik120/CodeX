#include <iostream>
#include <vector>

using namespace std;

int matrix_chain_multiplication(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k+1][j] + p[i] * p[k+1] * p[j+1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    vector<int> p = {40,20,30,10,30};
    int cost = matrix_chain_multiplication(p);
    cout << "Minimum cost of matrix chain multiplication: " << cost << endl;
    return 0;
}
