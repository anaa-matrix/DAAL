#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

void primMST(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // Start from vertex 1

    int minCost = 0;
    vector<Edge> mstEdges;
    vector<bool> inMST(n, false);
    int prev = 1; // Start from vertex 1
    cout << "Minimum Spanning Tree Edges:" << endl;

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        inMST[u] = true;
        minCost += weight;
        if (u != 1) { // Skip the initial vertex
            cout << "Edge: (" << prev << " - " << u << ") Weight: " << weight << endl;
        }
        prev = u;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[v]) {
                pq.push({edgeWeight, v});
                mstEdges.push_back(Edge(u, v, edgeWeight));
            }
        }
    }

    cout << "Graph Edges:" << endl;
    for (const Edge& edge : mstEdges) {
        cout << "(" << edge.u << " - " << edge.v << ") Weight: " << edge.weight << endl;
    }

    cout << "Minimum Cost: " << minCost << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1); // Adjust for 1-based indexing

    cout << "Enter edges in the format (u v weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    primMST(graph);

    return 0;
}