#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Contact {
    string name, phone;
    Contact *left, *right;
    Contact(const string& n, const string& p) : name(n), phone(p), left(nullptr), right(nullptr) {}
};

Contact* insertContact(Contact* root, const string& name, const string& phone) {
    if (!root) return new Contact(name, phone);
    if (name < root->name) root->left = insertContact(root->left, name, phone);
    else if (name > root->name) root->right = insertContact(root->right, name, phone);
    else root->phone = phone;
    return root;
}

Contact* searchContact(Contact* root, const string& name) {
    if (!root || root->name == name) return root;
    return name < root->name ? searchContact(root->left, name) : searchContact(root->right, name);
}

Contact* minimum(Contact* root) {
    while (root && root->left) root = root->left;
    return root;
}

Contact* deleteContact(Contact* root, const string& name) {
    if (!root) return nullptr;
    if (name < root->name) root->left = deleteContact(root->left, name);
    else if (name > root->name) root->right = deleteContact(root->right, name);
    else {
        if (!root->left) {
            Contact* child = root->right;
            delete root;
            return child;
        }
        if (!root->right) {
            Contact* child = root->left;
            delete root;
            return child;
        }
        Contact* successor = minimum(root->right);
        root->name = successor->name;
        root->phone = successor->phone;
        root->right = deleteContact(root->right, successor->name);
    }
    return root;
}

void displayAlphabetically(Contact* root) {
    if (!root) return;
    displayAlphabetically(root->left);
    cout << "Name: " << root->name << " | Phone: " << root->phone << '\\n';
    displayAlphabetically(root->right);
}

void destroy(Contact* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main() {
    Contact* root = nullptr;
    int choice;
    string name, phone;
    do {
        cout << "\\nCONTACT DIRECTORY\\n1. Insert/update contact\\n2. Search contact\\n3. Delete contact\\n4. Display alphabetically\\n0. Exit\\nChoice: ";
        if (!(cin >> choice)) break;
        cin.ignore(numeric_limits<streamsize>::max(), '\\n');
        switch (choice) {
            case 1:
                cout << "Enter name: "; getline(cin, name);
                cout << "Enter phone number: "; getline(cin, phone);
                root = insertContact(root, name, phone);
                cout << "Contact saved.\\n";
                break;
            case 2: {
                cout << "Enter name to search: "; getline(cin, name);
                Contact* found = searchContact(root, name);
                if (found) cout << "Found: " << found->name << " | " << found->phone << '\\n';
                else cout << "Contact not found.\\n";
                break;
            }
            case 3:
                cout << "Enter name to delete: "; getline(cin, name);
                if (searchContact(root, name)) {
                    root = deleteContact(root, name);
                    cout << "Contact deleted.\\n";
                } else cout << "Contact not found.\\n";
                break;
            case 4:
                if (!root) cout << "Directory is empty.\\n";
                else displayAlphabetically(root);
                break;
            case 0: cout << "Exiting directory.\\n"; break;
            default: cout << "Invalid choice.\\n";
        }
    } while (choice != 0);
    destroy(root);
    return 0;
}
