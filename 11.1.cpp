#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Utility: Get height
int getHeight(Node* n) {
    return n ? n->height : 0;
}

// Utility: Get balance factor
int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

// Utility: Update height
void updateHeight(Node* n) {
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
}

// Right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Balance node
Node* balance(Node* n) {
    updateHeight(n);

    int bf = getBalance(n);

    // Left heavy
    if (bf > 1) {
        if (getBalance(n->left) < 0) {
            n->left = rotateLeft(n->left);
        }
        return rotateRight(n);
    }
    // Right heavy
    else if (bf < -1) {
        if (getBalance(n->right) > 0) {
            n->right = rotateRight(n->right);
        }
        return rotateLeft(n);
    }

    return n;
}

// Insert key
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // duplicate keys not allowed

    return balance(root);
}

// Find min node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Delete key
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    return balance(root);
}

// Search key
bool search(Node* root, int key) {
    if (!root) return false;
    if (key == root->key) return true;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

// Traversals
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

// Driver code
int main() {
    Node* root = nullptr;

    // Insert elements
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cout << "Deleting 40...\n";
    root = deleteNode(root, 40);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Searching 25: " << (search(root, 25) ? "Found" : "Not Found") << endl;
    cout << "Searching 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

    return 0;
}
