//3.cpp
//using oop to find the charge of parking for various cars

#include<iostream>

using namespace std;

class car{
    private:
        int carID;
        int rate;
        float time;
        float cost;
    public:
        void setCarID(int n){
            carID = n;
        }
        void setRate(int n){
            rate = n;
        }
        void setTime(float n){
            time = n;
        }
        
        void displayCost(){
            cost = time*rate;
            cout<<"Car ID : "<<carID<<" parked his car for "<<time<<" hours. His total charge is \"Rs "<<cost<<"\".\n";
        }
};

int main(){

    car lambugini, fedari, amrendra;

    lambugini.setCarID(1);
    fedari.setCarID(3);
    amrendra.setCarID(5);
    
    amrendra.setRate(100);
    fedari.setRate(555);
    lambugini.setRate(999);

    lambugini.setTime(1.5);
    fedari.setTime(2);
    amrendra.setTime(30.1);

    amrendra.displayCost();
    fedari.displayCost();
    lambugini.displayCost();

    return 0;
}