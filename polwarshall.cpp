#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Represents infinity

// Function to perform Warshall's algorithm
void floydWarshall(vector<vector<int>>& graph, int numVertices) {
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    // Initialize the adjacency matrix with INF representing no direct edges
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, INF));

    // Set the diagonal elements to 0 as there is no distance from a vertex to itself
    for (int i = 0; i < numVertices; i++) {
        graph[i][i] = 0;
    }

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter edges and their weights (from to weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from][to] = weight;
    }

    floydWarshall(graph, numVertices);

    cout << "Shortest distances between vertices:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << graph[i][j] << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}

// Enter the number of vertices: 4
// Enter the number of edges: 4
// Enter edges and their weights (from to weight):
// 0 3 10
// 2 3 1
// 1 2 3
// 0 1 5
// Shortest distances between vertices:
// 0       5       8       9
// INF     0       3       4
// INF     INF     0       1
// INF     INF     INF     0
// O(V^3)
// O(V^2)
