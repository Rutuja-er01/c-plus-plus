// Practical 5: Fixed-size Hash Table using Division Method and Linear Probing
#include <iostream>
using namespace std;

#define SIZE 10        // fixed table size (m)
#define EMPTY -1       // slot never used
#define DELETED -2     // slot whose key was deleted

int table[SIZE];

// Division method: h(key) = key mod m
int hashFunction(int key) {
    return key % SIZE;
}

// Returns index of key if found, otherwise -1
int searchIndex(int key) {
    int start = hashFunction(key);
    int index = start;

    do {
        if (table[index] == EMPTY)      // never used slot -> key cannot be further
            return -1;
        if (table[index] == key)
            return index;
        index = (index + 1) % SIZE;     // linear probing
    } while (index != start);           // stop when we come back to starting position

    return -1;
}

// Insert key
void insertKey(int key) {
    if (key < 0) {
        cout << "Enter a non-negative key.\n";
        return;
    }
    if (searchIndex(key) != -1) {
        cout << "Key already exists.\n";
        return;
    }

    int start = hashFunction(key);
    int index = start;

    do {
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            cout << "Key " << key << " inserted at index " << index << endl;
            return;
        }
        cout << "Collision at index " << index << endl;
        index = (index + 1) % SIZE;     // linear probing
    } while (index != start);

    cout << "Hash table is full. Cannot insert.\n";
}

// Search key
void searchKey(int key) {
    int index = searchIndex(key);
    if (index != -1)
        cout << "Key Found at index " << index << endl;
    else
        cout << "Key Not Found\n";
}

// Delete key (mark position as DELETED)
void deleteKey(int key) {
    int index = searchIndex(key);
    if (index != -1) {
        table[index] = DELETED;
        cout << "Key " << key << " deleted from index " << index << endl;
    } else {
        cout << "Key Not Found\n";
    }
}

// Display table from index 0 to m-1
void display() {
    cout << "\nIndex\tKey\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";
        if (table[i] == EMPTY)
            cout << "EMPTY";
        else if (table[i] == DELETED)
            cout << "DELETED";
        else
            cout << table[i];
        cout << endl;
    }
}

int main() {
    int choice, key;

    // initialize hash table
    for (int i = 0; i < SIZE; i++)
        table[i] = EMPTY;

    do {
        cout << "\n--- Hash Table (Linear Probing) ---\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insertKey(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                searchKey(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}