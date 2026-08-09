#include<iostream>
using namespace std;
class complex{
    int a,b;
    public:
    //creating a constructor
    //constructor is a special member function with same name as of class.it is automatically invoked whenever an object is created 
    //it is use to initialize the objects of its class
    complex(void);//constructor declaration
    void printNumber(){
        cout<<"your no is"<<a<<"+"<<b<<"i"<<endl;
    }
};
complex :: complex()//this is a default constructor as it takes no parameter
{
    a=10;
    b=0;
}
int main(){
    complex c;
    c.printNumber();
    return 0;
}
/*properties of constructor
1.it should be declared in public section of the class
2.they are automatically invoked whenever the object is created
3.they cannot have return values and not have return type
4.it can have default arguments
5.we cannot refer to there address*/