#include<iostream>
#include<cmath>
using namespace std;
void printDigits(int n){
    int sum=0;
    int count=0;
    while(n!=0){
    int digits =n%10;
    sum+=digits;
    count++;
    n=n/10;
}cout<<sum<<endl;
cout<<count<<endl;

}int main(){
    int n=1223;
    printDigits(n);
    cout<<(int)(log10(n)+1)<<endl;
    return 0;
}