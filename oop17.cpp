#include<iostream>
#include<cmath>
using namespace std;
class point{
    int a,b,c,d;
    public:
    point(int x1,int x2,int y1,int y2)
    {
        a=x1;
        b=x2;
        c=y1;
        d=y2;
    }
    double distance() const{
        return std::hypot(a - b, c - d);
    }
    friend void printDistance(const point &p){
     std::cout << "Distance: " << p.distance ()<< std::endl;
    }
};
int main() {
    
    int x1,x2,y1,y2;
    cout<<"x1 =";
    cin>>x1;
    cout<<"x2 =";
    cin>>x2;
    cout<<"y1 =";
    cin>>y1;
    cout<<"y2 =";
    cin>>y2;
    
      point p(x1,x2,y1,y2);
      printDistance(p);
    return 0;
}