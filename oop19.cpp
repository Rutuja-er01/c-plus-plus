#include<iostream>
using namespace std;
class simple{
    int data1;
    int data2;
    public:
    simple(int a,int b=10){
        data1=a;
        data2=b;
    }
    void printData();
};
void simple :: printData(){
    cout<<"the value of data is"<<data1<<"and"<<data2<<endl;
}
int main(){
    simple s(1);
    s.printData();
    return 0;
}