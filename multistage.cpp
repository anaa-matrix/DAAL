#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum cost using dynamic programming
int minCost(vector<vector<int>>& graph, int stages) {
    int n = graph.size();
    vector<int> cost(n, INT_MAX);
    vector<int> path(n, -1);

    cost[n - 1] = 0; // Set the cost of the last stage to 0

    // Dynamic programming to find the minimum cost
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != -1 && cost[j] != INT_MAX && (cost[j] + graph[i][j] < cost[i])) {
                cost[i] = cost[j] + graph[i][j];
                path[i] = j;
            }
        }
    }

    // Print the steps
    int current = 0;
    cout << "Path: " << current;
    while (path[current] != -1) {
        cout << " -> " << path[current];
        current = path[current];
    }
    cout << endl;

    return cost[0];
}

int main() {
    int stages;
    cout << "Enter the number of stages: ";
    cin >> stages;

    // Input multistage graph from the user
    vector<vector<int>> graph(stages, vector<int>(stages, -1));
    cout << "Enter the adjacency matrix for the multistage graph:" << endl;
    for (int i = 0; i < stages; ++i) {
        for (int j = 0; j < stages; ++j) {
            cin >> graph[i][j];
        }
    }

    int min_cost = minCost(graph, stages);

    cout << "Minimum cost: " << min_cost << endl;

    return 0;
}
