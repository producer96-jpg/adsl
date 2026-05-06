#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

int n;
string landmark[MAX];

// Node structure
struct node {
    int data;
    node* next;
};

node* adj[MAX];

// Create Graph
void createGraph() {
    int edges, u, v;

    cout << "Enter number of landmarks: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter landmark " << i << ": ";
        cin >> landmark[i];
        adj[i] = NULL;
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;

        node* newNode = new node();
        newNode->data = v;
        newNode->next = adj[u];
        adj[u] = newNode;
    }
}

// BFS
void BFS(int start) {
    queue<int> q;
    int visited[MAX] = {0};

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << landmark[v] << " ";

        node* temp = adj[v];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                q.push(temp->data);
            }
            temp = temp->next;
        }
    }
}

int main() {
    createGraph();

    int start;
    cout << "Enter starting index: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start);

    return 0;
}
