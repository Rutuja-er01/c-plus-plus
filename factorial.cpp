#include<iostream>
using namespace std;
int main(){
    int n=5;
    int factorial=1;
    for(int i=1;i<=n;i++){
     factorial=factorial*i;
    }
    cout<<"factorial is"<<factorial<<endl;
    return 0;
}