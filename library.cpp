#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter total number of library members: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of members must be positive." << endl;
        return 0;
    }

    vector<int> books(n);
    int total = 0;
    int zeroCount = 0;
    map<int, int> frequency;

    // Input borrowing count for each member
    for (int i = 0; i < n; i++) {
        cout << "Enter books borrowed by member "
             << i + 1 << ": ";
        cin >> books[i];

        if (books[i] < 0) {
            cout << "Invalid borrowing count." << endl;
            return 0;
        }

        total += books[i];
        frequency[books[i]]++;

        if (books[i] == 0) {
            zeroCount++;
        }
    }

    // Calculate average, highest and lowest
    double average = static_cast<double>(total) / n;

    int highest = *max_element(books.begin(), books.end());
    int lowest = *min_element(books.begin(), books.end());

    // Find mode (most frequent borrowing count)
    int maxFrequency = 0;

    for (const auto &item : frequency) {
        maxFrequency = max(maxFrequency, item.second);
    }

    cout << "\n--- Library Borrowing Report ---" << endl;
    cout << "Total books borrowed: " << total << endl;
    cout << "Average books borrowed: " << average << endl;
    cout << "Highest borrowing count: " << highest << endl;
    cout << "Lowest borrowing count: " << lowest << endl;
    cout << "Members who borrowed zero books: "
         << zeroCount << endl;

    cout << "Mode(s): ";

    for (const auto &item : frequency) {
        if (item.second == maxFrequency) {
            cout << item.first << " ";
        }
    }

    cout << "\nMaximum frequency: " << maxFrequency << endl;

    return 0;
}