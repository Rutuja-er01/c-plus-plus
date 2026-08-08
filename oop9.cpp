#include<iostream>
using namespace std;
class student{
    int age;
    string name;
    public:
    float marks;
    int roll_no;
    student(){
        age=19;
        name="ritu";
        marks=9.05;
        roll_no=4;
    }
     friend void  display(student s);
    };

   void display(student s){
    cout<<"age:"<<s.age<<endl;
    cout<<"name:"<<s.name<<endl;
    cout<<"roll_no:"<<s.roll_no<<endl;
    cout<<"marks:"<<s.marks<<endl;
}


int main(){
    student s;
    display(s);
    return 0;
}
