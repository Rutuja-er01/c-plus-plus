#include<iostream>
using namespace std;
class BankAccount{
    float balance;
    string accountHolder;
    public:
    double accountNumber;

BankAccount(){
    balance=10000;
    accountHolder="ritu";
    accountNumber=12345678;
}
friend void display(BankAccount b);
};
void display(BankAccount b){
    cout<<"balance"<<b.balance<<endl;
     cout<<"accountholder"<<b.accountHolder<<endl;
      cout<<"accountNumber"<<b.accountNumber<<endl;
}
int main(){
    BankAccount b;
    display(b);
    return 0;
}
