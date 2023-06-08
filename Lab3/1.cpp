//1.cpp
//use classes and objects to convert between temperatures

#include<iostream>

using namespace std;


class celcius{
    private:
        float temp;
    public:
        float toFahrenheit(){
            return 1.8*temp+32;
        }
        void storeValue(float t){
            temp = t;
        }
        void displayValue(){
            cout<<"The value stored here is : "<<temp<<" degrees Celcius."<<endl;
        }
};

class fahrenheit{
    private:
        float temp;
    public:
        float toCelcius(){
            return (temp-32)/1.8;
        }
        void storeValue(float t){
            temp = t;
        }
        void displayValue(){
            cout<<"The value stored here is : "<<temp<<" degrees Fahrenheit."<<endl;
        }
};




int main(){

    celcius c1,c2;
    fahrenheit f1,f2;

    c1.storeValue(0);
    f1.storeValue(212);

    cout<<"The initial values are: "<<endl;
    c1.displayValue();
    f1.displayValue();

    f2.storeValue(c1.toFahrenheit());
    c2.storeValue(f1.toCelcius());

    cout<<"The final values are: "<<endl;
    c2.displayValue();
    f2.displayValue();    




    return 0;
}