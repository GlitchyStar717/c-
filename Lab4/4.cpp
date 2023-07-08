//4.cpp
//copy constructor demonstration and static member use

#include<iostream>

using namespace std;

class vehicle{
    private:
        static int num_vehicle, rate;
        int vehicle_id, hours, charge;
    public:
        vehicle(int hh = 1){
            vehicle_id = num_vehicle;
            hours = hh;
            charge = (hours * rate);
            num_vehicle++;
            display_charge();

        }
        void display_charge(){
            if(vehicle_id>10){
                charge *= 0.9;
            }
            cout<<"Vehicle "<<vehicle_id<<" was created with total charge of "<< charge << ".\n";
        }
        ~vehicle(){
            num_vehicle--;
            cout<<"Vehicle "<<vehicle_id<<" was destroyed.\n";
        }
        vehicle(vehicle &another_vehicle){
            cout <<"Copy constructor called.\n";
            vehicle_id=another_vehicle.vehicle_id;
            hours = another_vehicle.hours;
            charge = another_vehicle.charge;
        }
};

int vehicle::num_vehicle=1;
int vehicle::rate = 4500;

int main(){
    //copy constructor
    vehicle v1;
    vehicle v2(v1);

    //greater than 10
    vehicle v[10];

    return 0;
}