//6.cpp
//Demonstrating the net Salary increased in 2010 from 2009 of 4 job roles;

#include<iostream>
#include<iomanip>

float newSalary(int oldSalary = 18000, int increment = 12){
    return static_cast <float> (oldSalary)*(100+increment)/100;
}

using namespace std;

int main(){

    int i;
    int oldSalaries[] = {35000, 25000, 24000, 18000};
    int increment[] = {9,10,12,12};
    char position[][20] = {"CEO","Information Officer", "System Analyst", "Programmer"};
    float salary2010;

    for (i=0;i<4;i++){
        salary2010 = newSalary(oldSalaries[i],increment[i]);
        cout << position[i] <<"'s salary in 2010 is going to be "<< salary2010<<endl;
    }

    return 0;
}