// 2.cpp
// operator overloading using friend function

#include <iomanip>
#include <iostream>

using namespace std;

class cartesian {  // co_ordinate class's full definition must be given before polar function because polar needs to see this add function in class co_ordinate. A forward declaration of co_ordinate class is not enough for polar class to declare this add function as its friend.
   private:
    float x, y, z;

   public:
    cartesian(float X = 0, float Y = 0, float Z = 0) : x(X), y(Y), z(Z) {}

    void display_co_ordinates() {
        cout << fixed << setprecision(2) << "(x , y) = (" << x << " , " << y << " , " << z << ")" << endl;
    }

    friend cartesian operator+(cartesian P, cartesian Q);
    friend cartesian operator-(cartesian P, cartesian Q);
};

cartesian operator-(cartesian P, cartesian Q) {
    float x_temp, y_temp, z_temp;
    x_temp = P.x - Q.x;
    y_temp = P.y - Q.y;
    z_temp = P.z - Q.z;
    return cartesian(x_temp, y_temp, z_temp);
}
cartesian operator+(cartesian P, cartesian Q) {
    float x_temp, y_temp, z_temp;
    x_temp = P.x + Q.x;
    y_temp = P.y + Q.y;
    z_temp = P.z + Q.z;
    return cartesian(x_temp, y_temp, z_temp);
}

int main() {
    cartesian cart(3.0, 4.0, 5.0), cart1(1.0, 2.5, 6.9), cart2;

    cart2 = cart + cart1;
    cart2.display_co_ordinates();
    cout << endl;
    cart2 = cart - cart1;
    cart2.display_co_ordinates();

    return 0;
}

/*
OUTPUT
(x , y) = (4.00 , 6.50 , 11.90)

(x , y) = (2.00 , 1.50 , -1.90)
*/