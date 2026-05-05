#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

// Create new node
Node* newNode(char ch) {
    Node* node = new Node;
    node->data = ch;
    node->left = node->right = NULL;
    return node;
}

// Check operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^');
}

// Construct tree from prefix
Node* constructTree(string prefix) {
    stack<Node*> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (!isOperator(ch)) {
            st.push(newNode(ch));
        } else {
            Node* node = newNode(ch);

            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();

            st.push(node);
        }
    }
    return st.top();
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Print expression with brackets
void printTree(Node* root) {
    if (root == NULL) return;

    if (isOperator(root->data)) cout << "(";

    printTree(root->left);
    cout << root->data;
    printTree(root->right);

    if (isOperator(root->data)) cout << ")";
}

// Postorder traversal (using stack)
void postorder(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Delete tree
void deleteTree(Node* root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string prefix = "+--a*bc/def";

    Node* root = constructTree(prefix);

    int choice = 0;

    while (choice != 5) {
        cout << "\n***** Expression Tree *****\n";
        cout << "1. Print Expression\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Delete Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printTree(root);
                cout << endl;
                break;

            case 2:
                inorder(root);
                cout << endl;
                break;

            case 3:
                postorder(root);
                cout << endl;
                break;

            case 4:
                deleteTree(root);
                root = NULL;
                cout << "Tree deleted\n";
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    }

    return 0;
}
