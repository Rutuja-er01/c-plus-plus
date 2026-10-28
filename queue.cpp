#include <iostream>
#include <queue>
#include <limits>
using namespace std;

struct Call {
    int customerId;
    int callTime;
};

class CallCenterQueue {
    queue<Call> q;   // FIFO

public:
    // Time: O(1), Space: O(1)
    void addCall(int customerId, int callTime) {
        q.push({customerId, callTime});            // insert at rear
        cout << "Call Added: ID " << customerId
             << ", Time " << callTime << endl;
    }

    // Time: O(1), Space: O(1)
    void answerCall() {
        if (isQueueEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Call c = q.front();                        // first call
        q.pop();                                   // remove from front
        cout << "Answered Call -> ID: " << c.customerId
             << ", Time: " << c.callTime << endl;
    }

    // Time: O(n), Space: O(n) because of the copy (no calls are removed)
    void viewQueue() {
        if (isQueueEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Calls waiting (Front -> Rear):" << endl;
        queue<Call> temp = q;                      // traverse a copy
        while (!temp.empty()) {
            Call c = temp.front();
            temp.pop();
            cout << "  ID: " << c.customerId
                 << " | Time: " << c.callTime << endl;
        }
    }

    // Time: O(1), Space: O(1)
    bool isQueueEmpty() {
        return q.empty();
    }
};

int main() {
    CallCenterQueue cc;
    int choice;

    do {
        cout << "\n--- Call Center Queue ---\n"
             << "1. Add Call\n2. Answer Call\n3. View Queue\n"
             << "4. Is Queue Empty?\n5. Exit\nEnter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input" << endl;
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1: {
                int id, t;
                cout << "Customer ID: ";
                cin >> id;
                cout << "Call Time: ";
                cin >> t;
                cc.addCall(id, t);
                break;
            }
            case 2: cc.answerCall(); break;
            case 3: cc.viewQueue(); break;
            case 4:
                cout << (cc.isQueueEmpty() ? "True - Queue is Empty"
                                           : "False - Queue Not Empty")
                     << endl;
                break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}