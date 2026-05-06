#include <iostream>
using namespace std;

// Node structure
struct Node {
    string word;
    string meaning;
    Node *left, *right;

    Node(string w, string m) {
        word = w;
        meaning = m;
        left = right = NULL;
    }
};

class BST {
    Node* root;

public:
    BST() {
        root = NULL;
    }

    // INSERT
    void insert(string word, string meaning) {
        root = insertRec(root, word, meaning);
    }

    Node* insertRec(Node* node, string word, string meaning) {
        if (node == NULL)
            return new Node(word, meaning);

        if (word < node->word)
            node->left = insertRec(node->left, word, meaning);
        else if (word > node->word)
            node->right = insertRec(node->right, word, meaning);
        else
            cout << "Duplicate word not allowed!\n";

        return node;
    }

    // SEARCH
    void search(string key) {
        Node* temp = root;
        int comparisons = 0;

        while (temp != NULL) {
            comparisons++;

            if (temp->word == key) {
                cout << "Found: " << temp->word << " => " << temp->meaning << endl;
                cout << "Comparisons: " << comparisons << endl;
                return;
            }

            if (key < temp->word)
                temp = temp->left;
            else
                temp = temp->right;
        }

        cout << "Word not found\n";
    }

    // UPDATE
    void update(string key) {
        Node* temp = root;

        while (temp != NULL) {
            if (temp->word == key) {
                cout << "Enter new meaning: ";
                cin >> temp->meaning;
                return;
            }

            if (key < temp->word)
                temp = temp->left;
            else
                temp = temp->right;
        }

        cout << "Word not found\n";
    }

    // INORDER (Ascending)
    void displayAsc() {
        cout << "\nAscending Order:\n";
        inorder(root);
        cout << endl;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->word << " : " << node->meaning << endl;
            inorder(node->right);
        }
    }

    // DELETE NODE (simple version)
    Node* deleteNode(Node* node, string key) {
        if (node == NULL) return NULL;

        if (key < node->word)
            node->left = deleteNode(node->left, key);

        else if (key > node->word)
            node->right = deleteNode(node->right, key);

        else {
            // 0 or 1 child
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // 2 children
            Node* temp = findMin(node->right);
            node->word = temp->word;
            node->meaning = temp->meaning;
            node->right = deleteNode(node->right, temp->word);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    void deleteWord(string key) {
        root = deleteNode(root, key);
    }
};

int main() {
    BST tree;
    int choice;
    string word, meaning;

    do {
        cout << "\n===== DICTIONARY BST =====";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Update";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word: ";
                cin >> word;
                cout << "Enter meaning: ";
                cin >> meaning;
                tree.insert(word, meaning);
                break;

            case 2:
                tree.displayAsc();
                break;

            case 3:
                cout << "Enter word to search: ";
                cin >> word;
                tree.search(word);
                break;

            case 4:
                cout << "Enter word to update: ";
                cin >> word;
                tree.update(word);
                break;

            case 5:
                cout << "Enter word to delete: ";
                cin >> word;
                tree.deleteWord(word);
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
