#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int longest_substring_k_vowels(string s, int k) {
    int n = s.length();
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    vector<int> dp(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt_vowels = 0;
        int start = i;
        for (int j = i; j <= n; j++) {
            if (vowels.count(s[j - 1])) {
                cnt_vowels++;
            }
            if (cnt_vowels == k + 1) {
                start = j;
                break;
            }
            if (cnt_vowels == k && j - start + 1 > dp[i - 1]) {
                dp[j] = j - start + 1;
                ans = max(ans, dp[j]);
            } else {
                dp[j] = dp[j - 1];
            }
        }
    }
    return ans;
}

int main() {
    string s = "artyebui";
    int k = 2;
    int length = longest_substring_k_vowels(s, k);
    cout << "Length of longest substring with " << k << " distinct vowels: " << length << endl;
    return 0;
}
