#include<iostream>
using namespace std;

//forward declaration
 class complex;
class calculator{
    public:
    int add(int a,int b){
        return (a+b);
    }
    int sumRealComplex(complex,complex);
        int sumComComplex(complex,complex);

};
class complex{
    int a,b;
    //individually declaring function as friend
   // friend int calculator::sumRealComplex(complex ,complex ) ;
    //friend int calculator::sumComComplex(complex ,complex ) ;
    friend class calculator; //declaring entire class as friend
    public:
    void setNumber(int n1,int n2){
        a=n1;
        b=n2;
    }
    void printNumber(){
        cout<<"your number is"<<a<<"+"<<b<<"i"<<endl;
    }
};
int calculator::sumRealComplex(complex o1, complex o2)
{
    return (o1.a + o2.a);
}
int calculator::sumComComplex(complex o1, complex o2)
{
    return (o1.b + o2.b);
}
int main(){
    complex o1,o2;
    o1.setNumber(1,4);
    o2.setNumber(2,3);
    calculator calc;
    int res=calc.sumRealComplex(o1,o2);
    cout<<"the sum of real part of o1 and o2 is "<<res<<endl;
    int res2=calc.sumComComplex(o1,o2);
    cout<<"the sum of imaginary part of o1 and o2 is "<<res2<<endl;
    return 0;
}