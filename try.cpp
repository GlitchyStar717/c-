//2.cpp
//function overloading sample using feet to inches converter

#include<iostream>
#include<iomanip>

using namespace std;

void convert(){
    //takes no argument
    int feet,inch;    
    cout<<"Enter value in feet"<<endl;
    cin>>feet;
    cout<<"The value in inches is : "<<feet*12<<endl;
    
} 

void convert(int *feet){
    //takes one argument of type pointer of int
    int inch;    
    cout<<"Enter value in feet"<<endl;
    cin>>*feet;
    cout<<"The value in inches is : "<<(*feet)*12<<endl;
    
} 

void convert(int feet, int inch){
    //takes two argument of type int feet and inch
    cout<<"Enter value in feet"<<endl;
    cin>>feet;
    inch = feet*12;
    cout<<"The value in inches is : "<<inch<<endl;
    
} 

int main(){
    int feet, inch;
    int *ptr;
    ptr=&feet;

    convert();
    convert(ptr);
    convert(feet,inch);

    return 0;
}