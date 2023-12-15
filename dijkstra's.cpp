#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Node {
    int vertex;
    int weight;
};

struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        return a.weight > b.weight;
    }
};

void printPath(vector<int>& parents, int node) {
    if (node == -1) {
        return;
    }
    printPath(parents, parents[node]);
    cout << node << " ";
}

void dijkstra(vector<vector<Node>>& graph, int start, vector<int>& distances, vector<int>& parents) {
    priority_queue<Node, vector<Node>, CompareNodes> pq;
    pq.push({start, 0});
    distances[start] = 0;
    parents[start] = -1;

    while (!pq.empty()) {
        int u = pq.top().vertex;
        int uDistance = pq.top().weight;
        pq.pop();

        cout << "Processing node: " << u << ", Distance from source: " << uDistance << endl;

        for (const Node& neighbor : graph[u]) {
            int v = neighbor.vertex;
            int weight = neighbor.weight;

            if (uDistance + weight < distances[v]) {
                distances[v] = uDistance + weight;
                pq.push({v, distances[v]});
                parents[v] = u;
                cout << "Updated distance to node " << v << ": " << distances[v] << " (Path: ";
                printPath(parents, v);
                cout << ")" << endl;
            }
        }
    }
}

int main() {
   
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<Node>> graph(vertices);

    cout << "Enter edges in the format (u v weight):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    vector<int> distances(vertices, INF);
    vector<int> parents(vertices, -1);

    cout << "Dijkstra's Algorithm Steps:" << endl;
    dijkstra(graph, startNode, distances, parents);

    cout << "Shortest distances from node " << startNode << " to all other nodes:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "To node " << i << ": ";
        if (distances[i] == INF) {
            cout << "INFINITY";
        } else {
            cout << distances[i] << " (Path: ";
            printPath(parents, i);
            cout << ")";
        }
        cout << endl;
    }

return 0;
}

/*Enter the number of vertices and edges: 5 8
Enter edges (from to weight):
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
0 3 3
2 3 2
 0
 4
 0 -> 3 -> 4 (Weight: 4)*/
//  Time Complexity: O((V + E) * log V)
// Space Complexity: O(V + E)