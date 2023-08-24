#include <iostream>

class FeetInch;  // Forward declaration

class MeterCentimeter {
private:
    int meters;
    int centimeters;

public:
    MeterCentimeter(int m, int cm) : meters(m), centimeters(cm) {}

    int getMeters() const {
        return meters;
    }

    int getCentimeters() const {
        return centimeters;
    }

    void setMeters(int m) {
        meters = m;
    }

    void setCentimeters(int cm) {
        centimeters = cm;
    }

    void display() const {
        std::cout << "Distance: " << meters << " meters " << centimeters << " centimeters" << std::endl;
    }

    // Conversion function from MeterCentimeter to FeetInch
    operator FeetInch() const;
};

class FeetInch {
private:
    int feet;
    int inches;

public:
    FeetInch(int ft, int in) : feet(ft), inches(in) {}

    int getFeet() const {
        return feet;
    }

    int getInches() const {
        return inches;
    }

    void setFeet(int ft) {
        feet = ft;
    }

    void setInches(int in) {
        inches = in;
    }

    void display() const {
        std::cout << "Distance: " << feet << " feet " << inches << " inches" << std::endl;
    }

    // Conversion function from FeetInch to MeterCentimeter
    operator MeterCentimeter() const;
};

// Conversion function from MeterCentimeter to FeetInch
MeterCentimeter::operator FeetInch() const {
    int totalInches = (meters * 100 + centimeters) / 2.54;
    int ft = totalInches / 12;
    int in = totalInches % 12;
    return FeetInch(ft, in);
}

// Conversion function from FeetInch to MeterCentimeter
FeetInch::operator MeterCentimeter() const {
    int totalCentimeters = (feet * 12 + inches) * 2.54;
    int m = totalCentimeters / 100;
    int cm = totalCentimeters % 100;
    return MeterCentimeter(m, cm);
}

int main() {
    // Create a distance in meter-centimeter
    MeterCentimeter distance1(3, 50);
    distance1.display();

    // Convert meter-centimeter to feet-inch
    FeetInch convertedDistance1 = distance1;
    convertedDistance1.display();

    // Create a distance in feet-inch
    FeetInch distance2(5, 8);
    distance2.display();

    // Convert feet-inch to meter-centimeter
    MeterCentimeter convertedDistance2 = distance2;
    convertedDistance2.display();

    return 0;
}
