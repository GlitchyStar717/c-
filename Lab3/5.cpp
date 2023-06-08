//5.cpp
//using classes for displaying reports and storing the employee's details

#include<iostream>

using namespace std;

class employee{
    private:
        int id, bonus, overTime;
    public:
        void setPara(int x, int y, int z){
            id=x;
            bonus=y;
            overTime=z;
        }
        void displayReport(){
            cout<<"An employee with employee ID "<<id<<" has received Rs "<<bonus<<" as a bonus and had worked "<<overTime<<" days as overtime in the year 2023."<<endl;
        }
};

int main(){

    int i,n,id,bonus,ot;
    cout<<"How many employee's data do you want to enter ? "<<endl;
    cin>>n;

    employee e[n];
    
    for (i=0; i<n; i++){
        cout<<"Enter employee ID : ";
        cin>>id;
        cout<<"Enter employee's bonus : ";
        cin>>bonus;
        cout<<"Enter employee's ot : ";
        cin>>ot;
        e[i].setPara(id,bonus,ot);
    }
    
    for (i=0; i<n; i++){
        e[i].displayReport();
    }

    return 0;
}