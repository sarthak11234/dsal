#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int bal;
    Node *left;
    Node *right;
};

class Tree {
public:
    Node* insert(Node*, Node*);
    Node* rotateRight(Node*);
    Node* rotateLeft(Node*);
    void display(Node*, int);
};

// Display the tree sideways
void Tree::display(Node* root, int space) {
    if (root == nullptr)
        return;

    display(root->right, space + 4);

    for (int i = 0; i < space; i++)
        cout << " ";
    cout << root->data << endl;

    display(root->left, space + 4);
}

// Insert with balancing
Node* Tree::insert(Node* root, Node* s) {
    if (root == nullptr)
        return s;

    if (s->data > root->data) {
        root->right = insert(root->right, s);
    } else {
        root->left = insert(root->left, s);
    }

    // Update balance factor (basic heuristic)
    if (root->left == nullptr && root->right != nullptr)
        root->bal = -1;
    else if (root->left != nullptr && root->right == nullptr)
        root->bal = 1;
    else
        root->bal = 0;

    // Rebalancing
    // Left-Left Case
    if (root->bal == 1 && root->left && root->left->bal == 1)
        root = rotateRight(root);

    // Right-Right Case
    else if (root->bal == -1 && root->right && root->right->bal == -1)
        root = rotateLeft(root);

    // Left-Right Case
    else if (root->bal == 1 && root->left && root->left->bal == -1) {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }

    // Right-Left Case
    else if (root->bal == -1 && root->right && root->right->bal == 1) {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }

    return root;
}

// Right rotation
Node* Tree::rotateRight(Node* root) {
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

// Left rotation
Node* Tree::rotateLeft(Node* root) {
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

int main() {
    Node* root = nullptr;
    Tree t;
    char choice;

    do {
        Node* s = new Node;
        cout << "\nEnter node value: ";
        cin >> s->data;
        s->bal = 0;
        s->left = nullptr;
        s->right = nullptr;

        root = t.insert(root, s);

        cout << "\nCurrent AVL Tree:\n";
        t.display(root, 0);

        cout << "\nDo you want to enter more elements? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
