//1.cpp
//USe structure and manipulators to assign values and display date.

#include<iostream>
#include<iomanip>

using namespace std;


struct time{
    short int date;
    short int month;
    unsigned short int year;
};

void assignValues(struct time *t1){
    t1->date=8;
    t1->month=6;
    t1->year=2023;
}

void printValues(struct time *t1){
    cout<<"The date today is: "<<setw(2)<<setfill('0')<<t1->date<<"/"<<setw(2)<<setfill('0')<<t1->month<<"/"<<t1->year<<endl;
}

int main(){

struct time t1;
assignValues(&t1);
printValues(&t1);

return 0;
    
}