#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node {
    char data;
    Node *left, *right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

class ExpressionTree {
    Node* root;

public:
    ExpressionTree() {
        root = NULL;
    }

    // Check operator
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    // Build tree from PREFIX expression
    void build(string exp) {
        stack<Node*> st;

        for (int i = exp.length() - 1; i >= 0; i--) {
            char c = exp[i];

            Node* node = new Node(c);

            // If operand → push
            if (!isOperator(c)) {
                st.push(node);
            }
            // If operator → pop 2 elements
            else {
                node->left = st.top(); st.pop();
                node->right = st.top(); st.pop();
                st.push(node);
            }
        }

        root = st.top();
    }

    // Inorder traversal
    void inorder(Node* t) {
        if (t != NULL) {
            inorder(t->left);
            cout << t->data << " ";
            inorder(t->right);
        }
    }

    // Non-recursive postorder (using 2 stacks)
    void postorder(Node* root) {
        if (root == NULL) return;

        stack<Node*> s1, s2;

        s1.push(root);

        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            s2.push(temp);

            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    Node* getRoot() {
        return root;
    }
};

// MAIN FUNCTION
int main() {
    ExpressionTree tree;
    int choice;
    string exp;

    do {
        cout << "\n===== Expression Tree =====";
        cout << "\n1. Enter Prefix Expression";
        cout << "\n2. Build Tree";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Postorder (Non-Recursive)";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter prefix expression: ";
                cin >> exp;
                break;

            case 2:
                tree.build(exp);
                cout << "Tree built successfully!\n";
                break;

            case 3:
                cout << "Inorder: ";
                tree.inorder(tree.getRoot());
                cout << endl;
                break;

            case 4:
                cout << "Postorder: ";
                tree.postorder(tree.getRoot());
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
