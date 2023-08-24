#include <iostream>

using namespace std;

class Distance {
   private:
    int meters, centi_meters;
    bool floated = false;

   public:
    Distance(int m, int cm) {
        meters = m;
        centi_meters = cm;
    }
    Distance(float m_in_float) {
        meters = static_cast<int>(m_in_float);
        centi_meters = (m_in_float - static_cast<int>(m_in_float)) * 100;
    }
    void show_value() {
        cout << "The value of Distance is : " << meters << "m and " << centi_meters << "cm.\n";
    }
    operator float() {
        float meters_float = meters + static_cast<float>(centi_meters) / 100;
        return meters_float;
    }
};

int main() {
    Distance d1(5, 81);
    d1.show_value();

    float x = d1, y = 1.77;
    cout << "Value of x is : " << x << endl;

    Distance d2(y);
    cout << "Value of y is : " << y << endl;

    d2.show_value();

    return 1;
}