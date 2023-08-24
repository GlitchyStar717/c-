// 4.cpp
// Illustrate RTTI by using dynamic_cast and typeid

#include <iostream>

using namespace std;

class Vehicle {
   protected:
    string brand;
    int price;

   public:
    Vehicle(string Brand = "Maruti", int Price = 500) : brand(Brand), price(Price) {}
    virtual void display_attributes() {
        cout << brand << " costs " << price << ".\n";
    }
};
class Bus : public Vehicle {
   private:
    int no_of_passangers;

   public:
    Bus(string Brand = "Maruti", int Price = 500, int NoOfPassangers = 30) : Vehicle(Brand, Price), no_of_passangers(NoOfPassangers) {}
    virtual void display_attributes() {
        Vehicle::display_attributes();
        cout << " This bus has seats for " << no_of_passangers << " passangers.\n\n";
    }
};

class Car : public Vehicle {
   private:
    int year_made;

   public:
    Car(string Brand = "Maruti", int Price = 500, int YearMade = 2022) : Vehicle(Brand, Price), year_made(YearMade) {}
    virtual void display_attributes() {
        Vehicle::display_attributes();
        cout << " This car was made in " << year_made << ".\n\n";
    }
};

class Bike : public Vehicle {
   private:
    int cc;

   public:
    Bike(string Brand = "Maruti", int Price = 500, int CC = 150) : Vehicle(Brand, Price), cc(CC) {}
    virtual void display_attributes() {
        Vehicle::display_attributes();
        cout << " This bike has " << cc << "cc engine.\n\n";
    }
};

int main() {
    Vehicle v1, *vptr;

    cout << typeid(vptr).name() << endl;

    Bus b1, *bptr;
    Car c1, *cptr;
    Bike bi1, *biptr;

    vptr = &v1;
    cout << typeid(*vptr).name() << endl
         << endl;  // Must be run after vptr = &v1;

    vptr = &b1;
    cout << typeid(*vptr).name() << endl;
    cout << typeid(vptr).name() << endl
         << endl;  // Isn't useful since it wont give the object it is pointed to but gives the class whose pointer it is declared as.

    vptr = &c1;
    cout << typeid(*vptr).name() << endl;
    cout << typeid(vptr).name() << endl
         << endl;  // Isn't useful since it wont give the object it is pointed to but gives the class whose pointer it is declared as.

    vptr = &bi1;
    cout << typeid(*vptr).name() << endl;
    cout << typeid(vptr).name() << endl
         << endl;  // Isn't useful since it wont give the object it is pointed to but gives the class whose pointer it is declared as.

    biptr = dynamic_cast<Bike*>(vptr);
    biptr->display_attributes();

    vptr = &b1;
    bptr = dynamic_cast<Bus*>(vptr);
    bptr->display_attributes();

    vptr = &c1;
    cptr = dynamic_cast<Car*>(vptr);
    cptr->display_attributes();

    
    vptr = &v1;
    cptr = dynamic_cast<Vehicle*>(vptr);
    cptr->display_attributes();



    return 0;
}

/*
OUTPUT
P7Vehicle
7Vehicle

3Bus
P7Vehicle

3Car
P7Vehicle

4Bike
P7Vehicle

Maruti costs 500.
 This bike has 150cc engine.

Maruti costs 500.
 This bus has seats for 30 passangers.

Maruti costs 500.
 This car was made in 2022.
 */