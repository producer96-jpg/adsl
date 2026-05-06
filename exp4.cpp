#include <iostream>
#include <cstring>
using namespace std;

struct WORD {
    char key[20];
    char meaning[100];
};

struct NODE {
    WORD data;
    NODE* left;
    NODE* right;
    int height;
};

// Get height
int height(NODE* n) {
    if (n == NULL) return 0;
    return n->height;
}

// Max
int max(int a, int b) {

    if (a > b){
        return a;
    } 
    else {
        return b;
    }
}

// Create node
NODE* createNode(WORD w) {
    NODE* temp = new NODE;
    temp->data = w;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

// Balance factor
int getBalance(NODE* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

/* LL Rotation */
NODE* LL(NODE* y) {
    NODE* x = y->left;
    NODE* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    cout << "\nLeft-Left Rotation";
    return x;
}

/* RR Rotation */
NODE* RR(NODE* x) {
    NODE* y = x->right;
    NODE* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    cout << "\nRight-Right Rotation";
    return y;
}

/* LR Rotation */
NODE* LR(NODE* node) {
    node->left = RR(node->left);
    cout << "\nLeft-Right Rotation";
    return LL(node);
}

/* RL Rotation */
NODE* RL(NODE* node) {
    node->right = LL(node->right);
    cout << "\nRight-Left Rotation";
    return RR(node);
}

// Insert function
NODE* insert(NODE* node, WORD w) {

    if (node == NULL)
        return createNode(w);

    if (strcmp(w.key, node->data.key) < 0)
        node->left = insert(node->left, w);

    else if (strcmp(w.key, node->data.key) > 0)
        node->right = insert(node->right, w);

    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL case
    if (balance > 1 && strcmp(w.key, node->left->data.key) < 0)
        return LL(node);

    // RR case
    if (balance < -1 && strcmp(w.key, node->right->data.key) > 0)
        return RR(node);

    // LR case
    if (balance > 1 && strcmp(w.key, node->left->data.key) > 0)
        return LR(node);

    // RL case
    if (balance < -1 && strcmp(w.key, node->right->data.key) < 0)
        return RL(node);

    return node;
}

// Inorder display
void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data.key << " : " << root->data.meaning << endl;
        inorder(root->right);
    }
}
NODE* search(NODE* root, char key[],int &count) {

    if (root == NULL) {
        return NULL;   // Not found
    }
    count++;

    int cmp = strcmp(key, root->data.key);

    if (cmp == 0) {
        return root;   // Found
    }
    else if (cmp < 0) {
        return search(root->left, key,count);   // Go left
    }
    else {
        return search(root->right, key,count);  // Go right
    }
}

int main() {
    NODE* root = NULL;
    WORD w;
    int choice;

    while (1) {
        cout << "\n********DICTIONARY STORAGE using AVL*********";
        cout << "\n1-ADD WORD";
        cout << "\n2-DISPLAY DICTIONARY";
        cout << "\n3-search node";
        cout << "\n4-EXIT";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\nEnter keyword: ";
                cin >> w.key;

                cout << "Enter meaning: ";
                cin >> w.meaning;

                root = insert(root, w);
                break;

            case 2:
                cout << "\nDictionary:\n";
                inorder(root);
                break;
            case 3: {
                char key[20];
                int count=0;
                cout << "\nEnter keyword to search: ";
                cin >> key;
            
                NODE* result = search(root, key,count);
            
                if (result != NULL) {
                    cout << "\nWord Found!";
                    cout << "\nMeaning: " << result->data.meaning << endl;
                    cout<<"comaprison needed"<<count;
                } else {
                    cout << "\nWord Not Found!";
                }
                break;
            }

            case 4:
                cout << "\nProgram Exits!!";
                return 0;

            default:
                cout << "\nWrong choice!";
        }
    }
}
