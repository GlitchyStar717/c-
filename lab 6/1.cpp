#include <iostream>

class Distance {
private:
    int meter;
    int centimeter;

public:
    Distance(int m, int cm) : meter(m), centimeter(cm) {}

    int getMeter() const {
        return meter;
    }

    int getCentimeter() const {
        return centimeter;
    }

    void setMeter(int m) {
        meter = m;
    }

    void setCentimeter(int cm) {
        centimeter = cm;
    }

    void display() const {
        std::cout << "Distance: " << meter << " meters " << centimeter << " centimeters" << std::endl;
    }

    float toMetersFloat() const {
        return meter + static_cast<float>(centimeter) / 100;
    }

    float toCentimetersFloat()const {
        return centimeter + static_cast<float>(meter)*100;
    }

};

int main() {
    // Create a distance object
    Distance distance(3, 50);
    distance.display();

    // Convert distance to meters in float
    float metersFloat = distance.toMetersFloat();
    std::cout << "Distance in meters (float): " << metersFloat << std::endl;

    float centimetersFloat = distance.toCentimetersFloat();
    std::cout << "Distance in centimeters (float): " << centimetersFloat << std::endl;

    return 0;
}
