#include<iostream>
using namespace std;
//destructor never takes an argument and never returns any value
int count=0;
class num{
    public:
    num(){
        count++;
        cout<<"this is the time when constructor is called for object number"<<count<<endl;
    }
    ~num(){
        cout<<"this is time when my destructor is called for object number"<<count<<endl;
        count--;
    }
};
int main(){
    cout<<"we are inside our main function"<<endl;
    cout<<"creating first object n1"<<endl;
    num n1;
    {
        cout<<"enterning this block"<<endl;
        cout<<"creating first object n1"<<endl;
        num n1;{
            cout<<"enterning the block"<<endl;
            cout<<"creating two more object"<<endl;
            num n2,n3;
            cout<<"exiting this block"<<endl;
             }
             cout<<"back to main"<<endl;
    }
}