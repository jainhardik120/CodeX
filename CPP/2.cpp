#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int solve(int N, vector<int> Passengers, vector<vector<int>> Edges) {
    vector<vector<int>> adj(N + 1); // Using 1-based indexing for nodes
    for (auto& edge : Edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int count = 0;
    function<bool(int, int)> dfs = [&](int u, int parent) {
        bool has_passenger = (Passengers[u - 1] == 1);
        bool child_has_passenger = false;
        for (int v : adj[u]) {
            if (v == parent) continue;
            bool res = dfs(v, u);
            child_has_passenger |= res;
        }
        if (has_passenger && !child_has_passenger) {
            ++count;
        }
        return has_passenger || child_has_passenger;
    };
    
    dfs(1, -1); // Start DFS from node 1 (root) with no parent
    return count;
}
int main() {
    int N = 8;
    vector<int> Passengers = {0, 0, 0 ,1, 0, 1, 1, 1 }; // 1-indexed in problem, but 0-indexed in array
    vector<vector<int>> Edges = {{4,5}, {8,4}, {7,4}, {1,8}, {6,8},{3,4}, {2,8}};
    
    cout << "Minimum buses needed: " << solve(N, Passengers, Edges) << endl;
    return 0;
}