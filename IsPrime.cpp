#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if(n < 2)
    {
        return false;
    }

    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    if(isPrime(6))
    {
        cout << "Prime number";
    }
    else
    {
        cout << "Not a prime number";
    }

    return 0;
}