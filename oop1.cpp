#include<iostream>
using namespace std;
    class Employee {
private:
    int a ,b,c;
public:
    int d,e;
    void setData(int a,int b,int c);
    void getData(){
    cout<<"a"<<a<<endl;
    cout<<"b"<<b<<endl;
    cout<<"c"<<c<<endl;
    cout<<"d"<<d<<endl;
    cout<<"e"<<e<<endl;
    }
};
void Employee :: setData(int a,int b,int c){

    this->a = a;
    this->b = b;
    this->c = c;
}
    int main(){
    Employee Piyu;
    Piyu.d=12   ;
        Piyu.e=10 ;
        Piyu.setData(1,2,5);
        Piyu.getData();
        
return 0;
}