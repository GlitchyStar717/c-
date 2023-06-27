//2.cpp
//function overloading sample using feet to inches converter

#include<iostream>
#include<iomanip>

using namespace std;

void convert(){
    //takes no argument
    int feet,inch;    
    cout<<"Feet : ";
    cin>>feet;
    cout<<"Inch = "<<feet*12<<endl;
    
} 

void convert(int *feet){
    //takes one argument of type pointer of int
    int inch;    
    cout<<"Feet : ";
    cin>>*feet;
    cout<<"Inch = "<<(*feet)*12<<endl;
    
} 

void convert(int feet, int inch){
    //takes two argument of type int feet and inch
    cout<<"Feet : ";
    cin>>feet;
    inch = feet*12;
    cout<<"Inch = "<<inch<<endl;
    
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