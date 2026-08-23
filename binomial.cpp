#include<iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;

    for(int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}

int binomial(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main() {
    int n = 5;
    int r = 2;

    cout << "Binomial = " << binomial(n, r);

    return 0;
}