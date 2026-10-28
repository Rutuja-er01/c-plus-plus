// Practical 4: Student Record Management System using Singly Linked List (simple version)
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int roll;
    string name;
    float marks;
    Node* next;
};

Node* head = NULL;

// 1. Add student (at end)
void addStudent() {
    Node* newNode = new Node;
    cout << "Enter Roll No: ";
    cin >> newNode->roll;
    cout << "Enter Name: ";
    cin >> newNode->name;
    cout << "Enter Marks: ";
    cin >> newNode->marks;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Student added.\n";
}

// 2. Delete student
void deleteStudent() {
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // if first node
    if (head->roll == roll) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Record deleted.\n";
        return;
    }

    Node* prev = head;
    Node* cur = head->next;
    while (cur != NULL) {
        if (cur->roll == roll) {
            prev->next = cur->next;
            delete cur;
            cout << "Record deleted.\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "Record Not Found.\n";
}

// 3. Update student
void updateStudent() {
    int roll;
    cout << "Enter Roll No to update: ";
    cin >> roll;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            cout << "Enter new Name: ";
            cin >> temp->name;
            cout << "Enter new Marks: ";
            cin >> temp->marks;
            cout << "Record updated.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Record Not Found.\n";
}

// 4. Search student
void searchStudent() {
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            cout << "Record Found -> Roll: " << temp->roll
                 << "  Name: " << temp->name
                 << "  Marks: " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Record Not Found.\n";
}

// 5. Sort students
void sortStudents() {
    if (head == NULL || head->next == NULL) {
        cout << "Nothing to sort.\n";
        return;
    }

    int field, order;
    cout << "Sort by (1. Roll No, 2. Marks): ";
    cin >> field;
    cout << "Order (1. Ascending, 2. Descending): ";
    cin >> order;

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = head; j->next != NULL; j = j->next) {
            bool swapNeeded = false;

            if (field == 1) {
                if (order == 1 && j->roll > j->next->roll) swapNeeded = true;
                if (order == 2 && j->roll < j->next->roll) swapNeeded = true;
            } else {
                if (order == 1 && j->marks > j->next->marks) swapNeeded = true;
                if (order == 2 && j->marks < j->next->marks) swapNeeded = true;
            }

            if (swapNeeded) {
                swap(j->roll, j->next->roll);
                swap(j->name, j->next->name);
                swap(j->marks, j->next->marks);
            }
        }
    }
    cout << "Records sorted.\n";
}

// 6. Display students
void displayStudents() {
    if (head == NULL) {
        cout << "No records.\n";
        return;
    }
    Node* temp = head;
    cout << "Roll No\tName\tMarks\n";
    while (temp != NULL) {
        cout << temp->roll << "\t" << temp->name << "\t" << temp->marks << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add\n2. Delete\n3. Update\n4. Search\n5. Sort\n6. Display\n7. Exit\n";
        cout << "Select operation: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: searchStudent(); break;
            case 5: sortStudents(); displayStudents(); break;
            case 6: displayStudents(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}