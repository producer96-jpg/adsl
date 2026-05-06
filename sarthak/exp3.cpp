#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;   // adjacency list
    vector<int> visited;

public:
    Graph(int nodes) {
        n = nodes;
        adj.resize(n + 1);
        visited.resize(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);   // directed graph
    }

    void resetVisited() {
        fill(visited.begin(), visited.end(), 0);
    }

    // DFS (recursive)
    void DFS(int v) {
        visited[v] = 1;
        cout << v << " ";

        for (int i : adj[v]) {
            if (!visited[i]) {
                DFS(i);
            }
        }
    }

    // BFS (using queue)
    void BFS(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i : adj[v]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    void display() {
        cout << "\nAdjacency List:\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " -> ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, e, u, v, start;

    cout << "Enter number of nodes: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.display();

    cout << "\nEnter starting node for DFS: ";
    cin >> start;
    g.resetVisited();
    g.DFS(start);

    cout << "\nEnter starting node for BFS: ";
    cin >> start;
    g.resetVisited();
    g.BFS(start);

    return 0;
}
