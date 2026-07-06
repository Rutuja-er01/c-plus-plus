#include<iostream>
#include<string>
using namespace std;
int main(){
 string name = "rutuja";
 cout<<"the name is"<<endl;
 cout<<"the length is"<<name.length()<<endl;
 cout<<"the name is"<<name.substr(1,35)<<endl;
 cout<<"the name is"<<name.substr(2,4)<<endl;
 return 0;
}