#include <iostream>
using namespace std;

const int SIZE = 11;
const int EMPTY = 0, OCCUPIED = 1, DELETED = 2;

class HashMap {
    int keys[SIZE]{};
    int values[SIZE]{};
    int states[SIZE]{};

    int hashFunction(int key) const {
        int index = key % SIZE;
        return index < 0 ? index + SIZE : index;
    }

public:
    bool put(int key, int value) {
        int start = hashFunction(key), firstDeleted = -1;
        for (int i = 0; i < SIZE; ++i) {
            int slot = (start + i) % SIZE;
            if (states[slot] == OCCUPIED && keys[slot] == key) {
                values[slot] = value;
                return true;
            }
            if (states[slot] == DELETED && firstDeleted == -1) firstDeleted = slot;
            if (states[slot] == EMPTY) {
                int destination = firstDeleted == -1 ? slot : firstDeleted;
                keys[destination] = key;
                values[destination] = value;
                states[destination] = OCCUPIED;
                return true;
            }
        }
        if (firstDeleted != -1) {
            keys[firstDeleted] = key;
            values[firstDeleted] = value;
            states[firstDeleted] = OCCUPIED;
            return true;
        }
        return false;
    }

    bool get(int key, int& value) const {
        int start = hashFunction(key);
        for (int i = 0; i < SIZE; ++i) {
            int slot = (start + i) % SIZE;
            if (states[slot] == EMPTY) return false;
            if (states[slot] == OCCUPIED && keys[slot] == key) {
                value = values[slot];
                return true;
            }
        }
        return false;
    }

    bool remove(int key) {
        int start = hashFunction(key);
        for (int i = 0; i < SIZE; ++i) {
            int slot = (start + i) % SIZE;
            if (states[slot] == EMPTY) return false;
            if (states[slot] == OCCUPIED && keys[slot] == key) {
                states[slot] = DELETED;
                return true;
            }
        }
        return false;
    }

    void display() const {
        cout << "\\nIndex\\tKey\\tValue\\tState\\n";
        for (int i = 0; i < SIZE; ++i) {
            cout << i << '\\t';
            if (states[i] == OCCUPIED) cout << keys[i] << '\\t' << values[i] << "\\tOccupied\\n";
            else if (states[i] == DELETED) cout << "-\\t-\\tDeleted\\n";
            else cout << "-\\t-\\tEmpty\\n";
        }
    }
};

int main() {
    HashMap map;
    int choice, key, value;
    do {
        cout << "\\n1. Insert/update\\n2. Search key\\n3. Delete key\\n4. Display table\\n0. Exit\\nChoice: ";
        if (!(cin >> choice)) return 0;
        switch (choice) {
            case 1:
                cout << "Enter integer key and value: "; cin >> key >> value;
                cout << (map.put(key, value) ? "Stored successfully.\\n" : "HashMap is full.\\n");
                break;
            case 2:
                cout << "Enter key: "; cin >> key;
                if (map.get(key, value)) cout << "Value: " << value << '\\n';
                else cout << "Key not found.\\n";
                break;
            case 3:
                cout << "Enter key: "; cin >> key;
                cout << (map.remove(key) ? "Key deleted.\\n" : "Key not found.\\n");
                break;
            case 4: map.display(); break;
            case 0: cout << "Exiting.\\n"; break;
            default: cout << "Invalid choice.\\n";
        }
    } while (choice != 0);
    return 0;
}
