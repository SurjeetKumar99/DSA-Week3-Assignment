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

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}
void destroy(Node* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int n, value;
    cout << "How many values? ";
    if (!(cin >> n) || n < 0) return 1;
    for (int i = 0; i < n; ++i) {
        cout << "Value " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }
    cout << "Inorder (Left, Root, Right): "; inorder(root);
    cout << "\\nPreorder (Root, Left, Right): "; preorder(root);
    cout << "\\nPostorder (Left, Right, Root): "; postorder(root);
    cout << '\\n';
    destroy(root);
    return 0;
}
