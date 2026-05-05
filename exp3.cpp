#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

int g[MAX][MAX], visited[MAX], n;

// Landmark names
string landmark[MAX];

// ---------- Linked List Node ----------
struct node {
    int data;
    node* next;
};

// Adjacency List
node* adj[MAX];

// ---------- Create Graph ----------
void createGraph() {
    int edges, u, v;

    cout << "Enter number of landmarks (nodes): ";
    cin >> n;

    // Input landmark names
    for (int i = 0; i < n; i++) {
        cout << "Enter name of landmark " << i << ": ";
        cin >> landmark[i];
    }

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        for (int j = 0; j < n; j++) {
            g[i][j] = 0;
        }
    }

    cout << "Enter number of connections (edges): ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;

        // Adjacency Matrix
        g[u][v] = 1;

        // Adjacency List
        node* newNode = new node();
        newNode->data = v;
        newNode->next = adj[u];
        adj[u] = newNode;
    }
}

// ---------- Display Matrix ----------
void displayMatrix() {
    cout << "\nAdjacency Matrix:\n   ";

    for (int i = 0; i < n; i++)
        cout << landmark[i] << "\t";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << landmark[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << "\t";
        }
        cout << endl;
    }
}

// ---------- Display List ----------
void displayList() {
    cout << "\nAdjacency List:\n";

    for (int i = 0; i < n; i++) {
        cout << landmark[i] << " -> ";
        node* temp = adj[i];

        while (temp != NULL) {
            cout << landmark[temp->data] << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// ---------- DFS (Matrix) ----------
void DFS(int v) {
    visited[v] = 1;
    cout << landmark[v] << " ";

    for (int i = 0; i < n; i++) {
        if (g[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// ---------- BFS (List) ----------
void BFS(int start) {
    queue<int> q;
    int visitedBFS[MAX] = {0};

    visitedBFS[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << landmark[v] << " ";

        node* temp = adj[v];
        while (temp != NULL) {
            if (!visitedBFS[temp->data]) {
                visitedBFS[temp->data] = 1;
                q.push(temp->data);
            }
            temp = temp->next;
        }
    }
}

// ---------- MAIN ----------
int main() {
    int choice, start;

    do {
        cout << "\n***** Graph Operations *****\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Display Adjacency List\n";
        cout << "4. DFS Traversal\n";
        cout << "5. BFS Traversal\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createGraph();
            break;

        case 2:
            displayMatrix();
            break;

        case 3:
            displayList();
            break;

        case 4:
            for (int i = 0; i < n; i++)
                visited[i] = 0;

            cout << "Enter starting landmark index: ";
            cin >> start;

            cout << "DFS Traversal: ";
            DFS(start);
            cout << endl;
            break;

        case 5:
            cout << "Enter starting landmark index: ";
            cin >> start;

            cout << "BFS Traversal: ";
            BFS(start);
            cout << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
