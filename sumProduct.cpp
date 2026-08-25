#include <iostream>
using namespace std;

void sumAndProduct(int arr[], int n) {
    int sum = 0;
    int product = 1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        product *= arr[i];
    }

    cout << "Sum = " << sum << endl;
    cout << "Product = " << product << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    sumAndProduct(arr, n);

    return 0;
}