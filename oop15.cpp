#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
    Complex(int,int);//constructor declaration
    void printNumber(){
        cout<<"your no is"<<a<<"+"<<b<<"i"<<endl;
    }
};
Complex :: Complex(int x,int y)//--->this is paramiterized constructor as it takes TWo parameter
{
    a=x;
    b=y;

}

int main(){
    //implicit call
    Complex a(4,6);
    a.printNumber();
    return 0;
}