#include <iostream>
using namespace std;

#define MAX 10

int g[MAX][MAX], visited[MAX], n;
string landmark[MAX];

// Create Graph
void createGraph() {
    int edges, u, v;

    cout << "Enter number of landmarks: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter landmark " << i << ": ";
        cin >> landmark[i];
    }

    // Initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = 0;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g[u][v] = 1;
    }
}

// DFS
void DFS(int v) {
    visited[v] = 1;
    cout << landmark[v] << " ";

    for (int i = 0; i < n; i++) {
        if (g[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main() {
    createGraph();

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int start;
    cout << "Enter starting index: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
