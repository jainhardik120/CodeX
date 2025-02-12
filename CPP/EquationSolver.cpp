#include <bits/stdc++.h>
using namespace std;

class Solution
{
    double calculateFromGraph(vector<vector<double>> &graph, int a, int b, int size, vector<bool> &visited){
        if(a==b){
            return 1.0;
        }
        for (int i = 0; i < size; i++)
        {
            if(!visited[i] && graph[a][i]!=-1.0){
                visited[i] = true;
                double x = calculateFromGraph(graph, i, b, size, visited);
                visited[i] = false;
                if(x!=-1.0){
                    return (graph[a][i]*x);
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, int> variables;
        int index = 0;
        for (int i = 0; i < equations.size(); i++)
        {
            string s = equations[i][0];
            if (variables.find(s) == variables.end())
            {
                variables[s] = index++;
            }
            s = equations[i][1];
            if (variables.find(s) == variables.end())
            {
                variables[s] = index++;
            }
        }
        vector<vector<double>> graph(index, vector<double>(index, -1));
        for (int i = 0; i < equations.size(); i++)
        {
            auto a = variables.find(equations[i][0]);
            auto b = variables.find(equations[i][1]);
            if (a == variables.end() || b == variables.end())
            {
                continue;
            }
            graph[a->second][b->second] = values[i];
            graph[b->second][a->second] = 1 / values[i];
        }
        for (int i = 0; i < index; i++)
        {
            for (int j = 0; j < index; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << "\n";
        }
        
        vector<double> sol;
        for (int i = 0; i < queries.size(); i++)
        {
            auto a = variables.find(queries[i][0]);
            auto b = variables.find(queries[i][1]);
            if (a == variables.end() || b == variables.end())
            {
                sol.push_back(-1.0);
                continue;
            }
            vector<bool> visited(index, false);
            sol.push_back(calculateFromGraph(graph, a->second, b->second, index, visited));
        }
        
        return sol;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values = {1.5, 2.5, 5.0};
    vector<vector<string>> queries = {};
    sol.calcEquation(equations, values, queries);
    return 0;
}