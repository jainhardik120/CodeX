#include <iostream>
#include <algorithm>

using namespace std;

int* processQueries(int N, int* A, int Q, int** queries) {
    int** OR_values = new int*[N];
    for (int i = 0; i < N; ++i) {
        OR_values[i] = new int[N];
        OR_values[i][i] = A[i];
        for (int j = i + 1; j < N; ++j) {
            OR_values[i][j] = OR_values[i][j - 1] | A[j];
        }
    }

    int* result = new int[Q];
    for (int i = 0; i < Q; ++i) {
        int index = queries[i][0];
        int value = queries[i][1];
        index--;
        int low = index, high = N - 1, minIndex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (OR_values[index][mid] >= value) {
                minIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (minIndex != -1) {
            minIndex++;
        }
        result[i] = minIndex;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < N; ++i) {
        delete[] OR_values[i];
    }
    delete[] OR_values;

    return result;
}

int main() {
    int N, Q;
    cout << "Enter the size of the array: ";
    cin >> N;
    int* A = new int[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << "Enter the number of queries: ";
    cin >> Q;
    int** queries = new int*[Q];
    cout << "Enter the queries (index value): ";
    for (int i = 0; i < Q; ++i) {
        queries[i] = new int[2];
        cin >> queries[i][0] >> queries[i][1];
    }

    // Process queries
    int* result = processQueries(N, A, Q, queries);

    // Output results
    cout << "Results:" << endl;
    for (int i = 0; i < Q; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Free dynamically allocated memory
    delete[] A;
    for (int i = 0; i < Q; ++i) {
        delete[] queries[i];
    }
    delete[] queries;
    delete[] result;

    return 0;
}
