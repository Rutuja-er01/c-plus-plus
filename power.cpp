#include<iostream>
using namespace std;

bool isPowerOfTwo(int n){
if(n<=0){
    return false;
}
return ((n&(n-1))==0);
}
int main(){
    int n=34;
    if (isPowerOfTwo(n)) {
        cout << "Power of 2";
    }
    else {
        cout << "Not a power of 2";
    }
return 0;
}