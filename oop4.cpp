#include<iostream>
using namespace std;
class employee{
    int Id;
    static int Count;
    public:
    void setData(void){
        cout<<"enter the Id"<<endl;
        cin>>Id;
        Count++;
    }
    void getData(void){
        cout<<"the Id of this employee is "<<Id<<" and this is employee number "<<Count<<endl;
        }
         static void getCount(void){
            cout<<"Total number of employees: "<<Count<<endl;
        }
};

//Count is static data member of class employee
int employee :: Count;//default value is zero
int main(){
    employee ritu,priya,tanu;
    ritu.setData();
    ritu.getData();
    employee :: getCount();

    priya.setData();
    priya.getData();
    employee :: getCount();

    tanu.setData();
    tanu.getData();
    employee :: getCount();
    return 0;
}