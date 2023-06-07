//4.cpp
//

#include<iostream>

using namespace std;

float &temp(float *t1, float *t2, float *old){
    if (*t1>*t2){
        *old = *t1;
        return *t1;
    }
    else{
        *old = *t2; 
        *t2 = *t1;
        return *t1;
    }
}

int main(){

    float t1, t2, value, old;
    
    
    cout<<"Enter first temperature: "<<endl;
    cin>>t1;
    cout<<"Enter second temperature: "<<endl;
    cin>>t2;

    cout<<"Enter third/ replacing temperature: "<<endl;
    cin>>value;

    temp(&t1 , &t2, &old)= value;

    cout<<"Old values for the temperature are : "<<old<<" and "<<t2<<endl;
    cout<<"New values for the temperature are : "<<t1<<" and "<<t2<<endl;

    return 0;
}