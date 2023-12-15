#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int vertices;
    vector<Edge> edges;

public:
    Graph(int v) : vertices(v) {}

    void addEdge(int source, int destination, int weight) {
        edges.push_back({source, destination, weight});
    }

    int kruskalMST() {
        int minimumCost = 0;
        vector<Edge> result;

        sort(edges.begin(), edges.end());

        vector<int> parent(vertices + 1, -1); // Adjust for 1-based indexing

        cout << "Stepwise Kruskal's Algorithm:" << endl;
        for (const Edge& edge : edges) {
            int root1 = find(parent, edge.source);
            int root2 = find(parent, edge.destination);

            if (root1 != root2) {
                result.push_back(edge);
                minimumCost += edge.weight;
                unionSets(parent, root1, root2);

                // Print the current edge being added to the MST and the updated MST
                cout << "Added Edge: " << edge.source << " - " << edge.destination << " : " << edge.weight << endl;
                cout << "Current MST:";
                for (const Edge& mstEdge : result) {
                    cout << " (" << mstEdge.source << " - " << mstEdge.destination << ")";
                }
                cout << " | Minimum Cost: " << minimumCost << endl;
            }
        }

        cout << "Final Minimum Spanning Tree:" << endl;
        for (const Edge& edge : result) {
            cout << edge.source << " - " << edge.destination << " : " << edge.weight << endl;
        }

        cout << "Minimum Cost: " << minimumCost << endl;

        return minimumCost;
    }

private:
    int find(vector<int>& parent, int vertex) {
        if (parent[vertex] == -1)
            return vertex;
        return find(parent, parent[vertex]);
    }

    void unionSets(vector<int>& parent, int root1, int root2) {
        parent[root1] = root2;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph graph(vertices);

    cout << "Enter the edges in the format 'source destination weight':" << endl;
    for (int i = 0; i < edges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    int minimumCost = graph.kruskalMST();

    return 0;
}