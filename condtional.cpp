#include<iostream>
using namespace std;
int main(){
    int marks;
    cout<<"Enter marks: ";
    cin>>marks;
    if (marks==100&&marks>=95){
        cout<<"distinction"<<endl;
    }
    else if(marks==90&&marks<95){
        cout<<"A+ Grade"<<endl;
    }
    else if(marks==80&&marks<90){
        cout<<"A Grade"<<endl;
    }
    else if(marks==70&&marks<80){
        cout<<"B Grade"<<endl;
    }
    else if(marks==60&&marks<70){
        cout<<"C Grade"<<endl;
    }
    else if(marks==50&&marks<60){
        cout<<"D Grade"<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }
    return 0;
}