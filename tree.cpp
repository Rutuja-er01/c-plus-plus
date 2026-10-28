// Practical No. 6: Binary Search Tree (BST) operations
// Insert, Search, Delete, Display (Inorder, Preorder, Postorder)

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// ---------- INSERTION ----------
Node* insert(Node* root, int key) {
    if (root == NULL)               // empty position found -> create node
        return new Node(key);

    if (key < root->data)           // smaller -> go left
        root->left = insert(root->left, key);
    else if (key > root->data)      // greater -> go right
        root->right = insert(root->right, key);
    else
        cout << "Duplicate value " << key << " not inserted.\n";

    return root;
}

// ---------- SEARCH ----------
bool search(Node* root, int key) {
    if (root == NULL)               // reached NULL -> not found
        return false;
    if (root->data == key)          // equal -> found
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// ---------- FIND MINIMUM (used for inorder successor) ----------
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// ---------- DELETION ----------
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        cout << "Key not found, cannot delete.\n";
        return root;
    }

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: two children
        else {
            Node* succ = findMin(root->right);          // inorder successor
            root->data = succ->data;                    // copy its value
            root->right = deleteNode(root->right, succ->data); // delete successor
        }
    }
    return root;
}

// ---------- TRAVERSALS (DISPLAY) ----------
void inorder(Node* root) {          // Left, Root, Right
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {         // Root, Left, Right
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {        // Left, Right, Root
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ---------- SAFE INPUT (prevents infinite loop on wrong/EOF input) ----------
// Returns false if input ended (EOF); keeps asking until a valid number is typed
bool readInt(int &x) {
    while (true) {
        if (cin >> x)
            return true;                 // valid integer read
        if (cin.eof())
            return false;                // input finished -> stop program
        cin.clear();                     // clear error state
        cin.ignore(10000, '\n');         // throw away the bad input
        cout << "Invalid input! Enter a number: ";
    }
}

// ---------- MAIN ----------
int main() {
    Node* root = NULL;
    int choice = 0, key;

    do {
        cout << "\n===== BST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display (Inorder)\n";
        cout << "5. Display (Preorder)\n";
        cout << "6. Display (Postorder)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        if (!readInt(choice)) break;     // stop if input ends

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                if (!readInt(key)) return 0;
                root = insert(root, key);
                break;

            case 2:
                cout << "Enter key to search: ";
                if (!readInt(key)) return 0;
                if (search(root, key))
                    cout << "Key Found!\n";
                else
                    cout << "Key NOT Found!\n";
                break;

            case 3:
                cout << "Enter key to delete: ";
                if (!readInt(key)) return 0;
                root = deleteNode(root, key);
                break;

            case 4:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

/*
SAMPLE RUN (using tree from your example):
Insert: 50, 30, 70, 20, 40, 60, 80
Inorder   : 20 30 40 50 60 70 80
Preorder  : 50 30 20 40 70 60 80
Postorder : 20 40 30 60 80 70 50
*/