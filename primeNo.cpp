#include<iostream>
using namespace std ;
int main(){
    int n=8;
    bool isPrime=true;
    for( int i=2;i<=n-1;i++){
    if(n%i==0){
    isPrime=false;
    break;
    }
}
if(isPrime==true){
cout<<"this is prime no";
}
else{
cout<<"this is not prime no";
}
return 0;
}