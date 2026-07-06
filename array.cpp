#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3};
    int marks[6];
    for (int i=0;i<6;i++)
    {
        cout<<"enter the marks of"<< i <<"the student"<<endl;
        cin>>marks[i];
    }
    for( int i=0;i<6;i++){
        cout<<"marks of "<<i<<"the student is"<<marks [i]<<endl;
    }
    return 0;
}