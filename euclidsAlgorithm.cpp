#include<iostream>
using namespace std;
int gcd(int a,int b){
    while(a>0 && b>0){
        if(a>b){
        a=a%b;
        }else{
            b=b%a;
        }
    }if(a==0){
        return b;
    }else{
        return a;
    }
}
int LCM(int a,int b){
    return (a*b)/gcd(a,b);
}
int main(){
    int a=12;
    int b=6;
    cout<<gcd(a,b)<<endl;
    cout<<LCM(a,b)<<endl;
    return 0;
}