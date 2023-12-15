#include <bits/stdc++.h>
using namespace std;

void floydsAlgorithm(vector<vector<int>>& graph) {
  int numVertices = graph.size();
  vector<vector<int>> dist(numVertices, vector<int>(numVertices, 0));

  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      if (i == j) {
        dist[i][j] = 0;
      } else {
        dist[i][j] = graph[i][j];
      }
    }
  }

  for (int k = 0; k < numVertices; k++) {
    for (int i = 0; i < numVertices; i++) {
      for (int j = 0; j < numVertices; j++) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }

      // Print intermediate step
      cout << "Step " << (k + 1) << ":\n";
      for (vector<int>& row : dist) {
        for (int value : row) {
          if (value == INT_MAX) {
            cout << "inf\t";
          } else {
            cout << value << "\t";
          }
        }
        cout << endl;
      }
      cout << endl;
    }
  }
}

int main() {
  int numVertices;
  cout << "Enter the number of vertices: ";
  cin >> numVertices;

  vector<vector<int>> graph(numVertices, vector<int>(numVertices));

  cout << "Enter the adjacency matrix (use 'inf' for infinity):\n";
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      string input;
      cin >> input;
      if (input == "inf") {
        graph[i][j] = INT_MAX;
      } else {
        graph[i][j] = stoi(input);
      }
    }
  }

  floydsAlgorithm(graph);

  return 0;
}

// Enter the number of vertices: 4

// 0 3 inf 7
// 8 0 2 inf
// 5 inf 0 1
// 2 inf inf 0

// O(V^3)
// O(V^2)