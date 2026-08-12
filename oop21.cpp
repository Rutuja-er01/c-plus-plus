#include<iostream>
using namespace std;
class Number{
    int a;
    public:
    Number(){
        a=0;
    }
    Number(int num){
        a=num;
    }//when there is no copy construtor found,compiler supplies its own copy constructor
    Number(Number &obj){
        cout<<"copy constructor called"<<endl;
        a=obj.a;
    }
    void display(){
        cout<<"the number of this obj is"<<a<<endl;
    }
};
int main(){
    Number x,y,z(45),z2;
    x.display();
    y.display();
    z.display();
    Number z1(x);//copy constructor is invocked
    z1.display();
    z2=z;//copy constructor is not called
    Number z3=z; //copy constructor invocked
    z3.display();
    //z1 should exacty
    return 0;
}