#include<iostream>
using namespace std;

void fibonacci(int n)
{
    int a = 0;
    int b = 1;

    for(int i = 1; i <= n; i++)
    {
        cout << a << " ";

        int next = a + b;
        a = b;
        b = next;
    }
}

int main()
{
    fibonacci(7);

    return 0;
}