#include<iostream>
using namespace std;
class point{
    int x,y;
    public:
    point(int a,int b){
        x = a;
        y = b;
    }
    void displayPoint(){
        cout<<"the point is ("<<x<<","<<y<<")"<<endl;
    }
    };
//create a function which takes 2 point objects and computes the distance between those points and make it a friend function
int main(){
    point p(1,1);
    p.displayPoint();
    point q(4,6);
    q.displayPoint();
  return 0;
}