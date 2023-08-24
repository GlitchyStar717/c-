// 5.cpp
// Making 3

#include <iostream>

using namespace std;

class BaseComplex {
   protected:
    float a, b;

   public:
    BaseComplex(float x = 0, float y = 0) : a(x), b(y) {}
    float get_a() {
        float temp;
        cout << "Give a : ";
        cin >> temp;
        return temp;
    }
    float get_b() {
        float temp;
        cout << "Give b : ";
        cin >> temp;
        return temp;
    }

    void display() {
        cout << "a + ib = " << a << " + i" << b << endl;
    }
};
class DerivedComplex : public BaseComplex {
   public:
    DerivedComplex(float x = 0, float y = 0) {
        a = x;
        b = y;
        BaseComplex::a = BaseComplex::get_a();
        BaseComplex::b = BaseComplex::get_b();

    }
    void addValue() {
        float a_t, b_t;
        a_t = DerivedComplex::a + BaseComplex::a;
        b_t = DerivedComplex::b + BaseComplex::b;
        this->display();
        BaseComplex::display();

        BaseComplex added(a_t, b_t);
        added.display();
    }
};

int main() {
    DerivedComplex d1(3, 4);
    d1.addValue();

    return 0;
}