#include<iostream>
#include<string>
using namespace std;
    class employee
    {
    protected:
        string name;
        int salary;
    public:
        employee(string n, int s)
          {
            name=n;
            salary =s;
          }
          virtual void display()
          {
            cout << "employee name:"<<name<<endl;
            cout<<"salary:"<<salary<<endl;
          }
          virtual void work()
        {
          cout << name <<"is working."<< endl;
        }
    };
    class programmer : public employee{
        private:
          string language;
        public:
           programmer(string n, int s,string lang)
           :employee(n,s)
           {
            language=lang;
           }  
           void display() override
           {
            cout<<"programmer name:"<<name<<endl;
            cout<<"salary:"<<salary<<endl;
            cout<<"language:"<<language<<endl;
           }
           void work()override
           {
            cout << name <<" is coding in"<<language<<"."<<endl;
           }
        };
        int main(){
            programmer p1("rutuja",80000,"c++");
            p1.display();
            p1.work();
            employee *e=&p1;
            e->display();
            e->work();
            return 0;
        }
    