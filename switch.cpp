#include<iostream>
using namespace std;
int main(){
    int age;
    cout<<"enter your age"<<endl;
    cin>>age;
    switch(age){
     case 12:
      cout<<"you are 12 year old"<<endl;
      break;
     case 18:
      cout<<"you are 18 year old"<<endl;
      break;
     case 28:
      cout<<"you are 28 year old"<<endl;
      break;
     default:
      cout<<"invalid age"<<endl;
    }
    return 0;
}