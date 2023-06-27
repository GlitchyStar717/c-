//7.cpp
//Extra question for this lab of adding two complex numbers

#include<iostream>


using namespace std;

struct complex{
    float a;
    float b;
};

void addComplex(struct complex *c1, struct complex *c2, struct complex *c3){
    c3->a = c1->a + c2->a;
    c3->b = c1->b + c2->b;
}

void displayComplex(struct complex *c1){
    cout<<c1->a<<"+"<<c1->b<<"i.\n";
    
}

int main(){
    struct complex x,y,z;
    x.a=5;
    x.b=6;
    y.a=2;
    y.b=-4;

    cout<<"The initial complex numbers are : \n";
    displayComplex(&x);
    displayComplex(&y);
    addComplex(&x,&y,&z);
    cout<<"The addition of the two complex numbers are : \n";
    displayComplex(&z);
    
    
    return 0;
    
}