#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; ++c) {
        cout << "Trying color " << c << " for vertex " << v << endl;
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            cout << "Color " << c << " assigned to vertex " << v << endl;

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true; // If assigning color 'c' to vertex 'v' leads to a solution, return true
            }

            color[v] = 0; // Backtrack: Try a different color if the current one doesn't lead to a solution
            cout << "Backtrack: Reset color of vertex " << v << endl;
        }
    }

    return false; // No color can be assigned to this vertex that leads to a solution
}

void graphColoring(const vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0);

    if (graphColoringUtil(graph, m, color, 0)) {
        cout << "Graph can be colored with at most " << m << " colors. Colors assigned to vertices:" << endl;
        for (int i = 0; i < graph.size(); ++i) {
            cout << "Vertex " << i << ": Color " << color[i] << endl;
        }
    } else {
        cout << "Graph cannot be colored with " << m << " colors." << endl;
    }
}

int main() {
    int n; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Initialize the adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix (1 if there is an edge, 0 otherwise):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int m; // Number of colors
    cout << "Enter the number of colors: ";
    cin >> m;

    graphColoring(graph, m);

    return 0;
}
