#include<iostream>
using namespace std;
class shop{
    int itemId[100];
    int itemPrice[100];
    int counter;
    public:
    void initCounter(void){counter=0;}
    void setPrice(void);
    void displayPrice(void);
};
void shop :: setPrice(void){
    cout<<"enter Id of your item no "<<counter+1<<endl;
    cin>>itemId[counter];
    cout<<"enter Price of your item"<<endl;
    cin>>itemPrice[counter];
    counter++;
}
void shop :: displayPrice(void){
    for(int i=0;i<counter;i++){
        cout<<"The price of item with Id "<<itemId[i]<<endl;
         cout<<"The price of item with Id "<<itemPrice[i]<<endl;
    }
}
int main(){
    shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();
    return 0;
}