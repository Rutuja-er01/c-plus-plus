#include<iostream>
using namespace std;
int add(int a, int b)
{
    return a+b;
}
int main(){
    int a,b;
    cout<<"enter first number:";
    cin>>a;
    cout<<"enter second number:";
    cin>>b;
    cout<<"the function returned:"<<add(a,b);
    return 0;
}