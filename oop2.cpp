#include<iostream>
#include<string>
using namespace std;
class Binary{
    
    private:
    string s;
    public:
    void read(void);
    void chk_bin(void);
    void ones(void);
    void display(void);
};
void Binary :: read(void){
    
    cout<<"Enter a binary number"<<endl;
    cin>>s;
}
void Binary ::  chk_bin(void){
    for(int i=0;i<s.length();i++){
        if(s.at(i)!='0' && s.at(i)!='1'){
            cout<<"Incorrect binary format"<<endl;
            exit(0);
        }
    }
}
void Binary :: ones(void){
    chk_bin();
for(int i=0;i<s.length();i++){
    if(s.at(i)=='0'){
        s.at(i)='1';
    }
    else{
        s.at(i)='0';
    }
}
}
    void Binary :: display(void){
        cout<<"Displaying your binary number"<<endl;
        for(int i=0;i<s.length();i++){
            cout<<s.at(i);
        }
        cout<<endl;
    }
int main(){
    //OOPS classes and objects
    //C++ initially called C with classes by Bjarne Stroustrup in 1979 at Bell Labs
    //class --> extension of structure (in c)
    // structure had limitations
    // --members are public
    // --no methods
    // classes -->strutures+more
    // classes --> can have methods and properties
    // classes --> can make few members as private & few as public
    // structure in c++ are typedefed
    //you can declare objects along with the class declaration like this
    /*class Employee{
    class definition
    } ritu,tanu,priya;*/
     //ritu.salary=8 makes no sense if salary is private
     //nesting of member functions
     //::-- scope resolution operator
     Binary b;
     b.read();
     //b.chk_bin();
     b.display();
        b.ones();
        b.display();
     return 0;
}