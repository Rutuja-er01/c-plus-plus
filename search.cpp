#include<iostream>
using namespace std;
int main(){
  int i,mid,key;
  cout<<"enter the key"<<endl;
  cin>>key;
  int arr[5]={10,20,30,40,50};
  for(i=0;i<5;i++){
    if(arr[i]==key){
    cout<<arr[i]<<endl;
    break;
  }
}
  if(i<5){
    cout<<"key is found using linear search"<<endl;
  }else{
    cout<<"key is not found using linear search"<<endl;
  }
  int low=0;
  int high=4;
  while(low<=high){
    mid=low+(high-low)/2;
    if(arr[mid]==key){
      cout<<arr[mid]<<endl;
      break;
    }
    else if(arr[mid]<key){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
  }
  if(low<=high){
    cout<<"key is found using binary search"<<endl;
  }else{
    cout<<"key is not found using binary search"<<endl;
  }return 0;
}
