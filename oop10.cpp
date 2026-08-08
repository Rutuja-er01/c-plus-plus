#include<iostream>
using namespace std;
class Book{
   float price;
   string tittle;
   public:
   float pages;
   Book(){
    price= 100;
    tittle= "zero to one";
    pages= 120;
   }
   friend void display(Book B);
};
void display(Book B){
    cout<<"price" <<B. price<<endl;
    
    cout<<"price" <<B. tittle<<endl;
    
    cout<<"price" <<B. pages<<endl;
    
}
int main(){
    Book B;
    display(B);
    return 0;
};