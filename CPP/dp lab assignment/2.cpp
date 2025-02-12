#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sum_contiguous_subsequence(vector<int>& arr) {
    int n = arr.size();
    int max_sum = arr[0], curr_sum = arr[0];
    for (int i = 1; i < n; i++) {
        curr_sum = max(curr_sum + arr[i], arr[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main() {
    vector<int> arr = {5, 15, -30, 10, -5, 40, 10};
    int max_sum = max_sum_contiguous_subsequence(arr);
    cout << "Maximum sum contiguous subsequence: " << max_sum << endl;
    return 0;
}
