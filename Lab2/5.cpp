//5.cpp
//Using inline function for generating net Salary given gross salary and 10% income tax.

#include<iostream>

inline float netSalary(float salary){
    return salary*0.9;      // 10%income tax
}

using namespace std;

int main(){

    float salary;
    cout<<"Enter your salary"<<endl;
    cin>>salary;
    cout<<"Your net Salary is : "<<netSalary(salary)<<"."<<endl;
    return 0;
}