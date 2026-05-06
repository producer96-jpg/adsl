#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    string key, meaning;
    Node *left, *right;
    int height;

    Node(string k, string m) {
        key = k;
        meaning = m;
        left = right = NULL;
        height = 1;
    }
};

class AVL {
    Node* root;

    int getHeight(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n ? getHeight(n->left) - getHeight(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, string key, string meaning) {
        if (!node)
            return new Node(key, meaning);

        if (key < node->key)
            node->left = insert(node->left, key, meaning);
        else if (key > node->key)
            node->right = insert(node->right, key, meaning);
        else
            return node; // duplicate keys not allowed

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // Rotations
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);              // LL

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);               // RR

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);   // LR
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right); // RL
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " : " << root->meaning << endl;
            inorder(root->right);
        }
    }

    void search(Node* root, string key) {
        int count = 0;
        while (root) {
            count++;
            if (key == root->key) {
                cout << "Found in " << count << " comparisons\n";
                return;
            }
            root = (key < root->key) ? root->left : root->right;
        }
        cout << "Not found\n";
    }

public:
    AVL() { root = NULL; }

    void add(string k, string m) {
        root = insert(root, k, m);
    }

    void display() {
        inorder(root);
    }

    void find(string k) {
        search(root, k);
    }
};

int main() {
    AVL dict;
    int ch;
    string key, meaning;

    do {
        cout << "\n1.Add\n2.Display\n3.Search\n4.Exit\nChoice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) {
        case 1:
            cout << "Enter key: ";
            getline(cin, key);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            dict.add(key, meaning);
            break;

        case 2:
            dict.display();
            break;

        case 3:
            cout << "Enter key: ";
            getline(cin, key);
            dict.find(key);
            break;
        }
    } while (ch != 4);

    return 0;
}
