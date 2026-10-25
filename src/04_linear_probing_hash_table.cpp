#include <iostream>
using namespace std;

const int TABLE_SIZE = 7;
const int EMPTY = -1;

class HashTable {
    int table[TABLE_SIZE];
    int hashFunction(int key) const {
        int index = key % TABLE_SIZE;
        return index < 0 ? index + TABLE_SIZE : index;
    }
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) table[i] = EMPTY;
    }
    bool insert(int key) {
        int start = hashFunction(key);
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int index = (start + i) % TABLE_SIZE;
            if (table[index] == key) return true;
            if (table[index] == EMPTY) {
                table[index] = key;
                return true;
            }
        }
        return false;
    }
    bool search(int key) const {
        int start = hashFunction(key);
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int index = (start + i) % TABLE_SIZE;
            if (table[index] == EMPTY) return false;
            if (table[index] == key) return true;
        }
        return false;
    }
    void display() const {
        cout << "\\nIndex\\tValue\\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << '\\t';
            if (table[i] == EMPTY) cout << "Empty\\n";
            else cout << table[i] << '\\n';
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;
    do {
        cout << "\\n1. Insert key\\n2. Search key\\n3. Display table\\n0. Exit\\nChoice: ";
        if (!(cin >> choice)) return 0;
        switch (choice) {
            case 1:
                cout << "Enter integer key: "; cin >> key;
                cout << (ht.insert(key) ? "Inserted (or already present).\\n" : "Table is full.\\n");
                break;
            case 2:
                cout << "Enter key: "; cin >> key;
                cout << (ht.search(key) ? "Key found.\\n" : "Key not found.\\n");
                break;
            case 3: ht.display(); break;
            case 0: cout << "Exiting.\\n"; break;
            default: cout << "Invalid choice.\\n";
        }
    } while (choice != 0);
    return 0;
}
