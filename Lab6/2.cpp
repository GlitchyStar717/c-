// 2.cpp
// m-cm and feet-inches conversion using classes conversion constructor

#include <iostream>

using namespace std;

class English_distance;

class Imperial_Distance {
   private:
    float feet, inch;

   public:
    Imperial_Distance(float ft = 0, float in = 0) {
        feet = ft;
        inch = in;
    }
    operator English_distance();
    void display_value() {
        cout << feet << "' " << inch << "\".\n";
    }
};

class English_distance {
   private:
    float meters, centi_meters;

   public:
    English_distance(float m = 0, float cm = 0) {
        meters = m;
        centi_meters = cm;
    }
    operator Imperial_Distance();

    void display_value() {
        cout << meters << "m " << centi_meters << "cm.\n";
    }
};

Imperial_Distance::operator English_distance() {
    float temp, m, cm;
    temp = (feet + inch / 12) * 30.48;
    m = static_cast<int>(temp / 100);
    cm = temp - (m * 100);
    return English_distance(m, cm);
}

English_distance::operator Imperial_Distance() {
    float temp, feet, inch;
    temp = (meters * 100 + centi_meters) * 0.3937;
    feet = static_cast<int>(temp / 12);
    inch = (temp - feet * 12);
    return Imperial_Distance(feet, inch);
}

int main() {
    Imperial_Distance I1(5, 8), I2;
    English_distance E1(1, 30), E2,E3;

    I1.display_value();
    E1.display_value();
    cout << endl;

    I2 = E1.operator Imperial_Distance();
    cout<< "HI"<<endl;
    E2 = English_distance(I1);
    E3 = I1.operator English_distance(I1);

    E2.display_value();
    I2.display_value();

    return 0;
}