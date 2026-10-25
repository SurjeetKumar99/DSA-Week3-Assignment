#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    explicit Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

bool search(Node* root, int target) {
    if (!root) return false;
    if (root->data == target) return true;
    return target < root->data ? search(root->left, target) : search(root->right, target);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void destroy(Node* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int n, value, target;
    cout << "How many values? ";
    if (!(cin >> n) || n < 0) return 1;
    for (int i = 0; i < n; ++i) {
        cout << "Value " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }
    cout << "BST in sorted order: ";
    inorder(root);
    cout << "\\nEnter value to search: ";
    cin >> target;
    cout << (search(root, target) ? "Value found.\\n" : "Value not found.\\n");
    destroy(root);
    return 0;
}
