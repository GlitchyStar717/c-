// 1.cpp
// friend function of various types

#include <cmath>  //for using sine and cosine functions.
#include <iomanip>
#include <iostream>

inline float PI() {
    return 3.14159;
}

using namespace std;

class polar;  // Forward declaration of the polar class for making class co_ordinate know that polar is a class when its add function needs a polar datatype

class cartesian {  // co_ordinate class's full definition must be given before polar function because polar needs to see this add function in class co_ordinate. A forward declaration of co_ordinate class is not enough for polar class to declare this add function as its friend.
   private:
    float x, y;

   public:
    cartesian(float X=0, float Y=0) : x(X), y(Y) {}

    void display_co_ordinates() {
        cout << fixed << setprecision(2) << "(x , y) = (" << x << " , " << y << ")" << endl;
    }

    friend class polar;
    friend cartesian multiply(cartesian, polar);
    friend cartesian divide(cartesian, polar);
    friend cartesian subtract(cartesian, polar);

    void add(polar p);  // You can not define the entire function here. For this function to be able to use the data members of polar, its full definition must be after the full definition of polar function
};

class polar {
   private:
    float r, theta;

   public:
    polar(float R=0, float Theta=0) : r(R), theta(Theta) {}

    friend void cartesian::add(polar);
    friend cartesian multiply(cartesian, polar);
    friend cartesian divide(cartesian, polar);
    friend cartesian subtract(cartesian, polar);

    int is_greater_than(cartesian P) {
        float r_P;
        r_P = sqrt(P.x * P.x + P.y * P.y);
        if (r > r_P) {
            return 1;
        } else if (r == r_P) {
            return 0;
        } else {
            return -1;
        }
    }

    bool lies_in_same_quadrant(cartesian P) {
        int quadrant_P, quadrant_R;
        float theta_temp;
        if (P.x >= 0) {
            if (P.y >= 0) {
                quadrant_P = 1;
            }
            else {
                quadrant_P = 4;
            }
        }
        else {
            if (P.y >= 0) {
                quadrant_P = 2;
            }
            else {
                quadrant_P = 3;
            }
        }
        theta_temp = theta - static_cast<int>(theta / (2 * PI())) * 2 * PI();
        if (theta_temp <= PI() / 2) {
            quadrant_R = 1;
        } else if (theta_temp <= PI()) {
            quadrant_R = 2;
        } else if (theta_temp <= 3 * PI() / 2) {
            quadrant_R = 3;
        } else {
            quadrant_R = 4;
        }

        if (quadrant_P == quadrant_R) {
            return true;
        } else {
            return false;
        }
    }
};

void cartesian::add(polar p) {
    float r_x, r_y;
    r_x = p.r * cos(p.theta);
    r_y = p.r * sin(p.theta);

    x = x + r_x;
    y = y + r_y;
}

cartesian multiply(cartesian P, polar Q) {
    float r_x, r_y;
    r_x = P.x * Q.r * cos(Q.theta);
    r_y = P.y * Q.r * sin(Q.theta);
    return cartesian(r_x, r_y);
}
cartesian divide(cartesian P, polar Q) {
    float r_x = 717, r_y= 717;
    if ((Q.theta - static_cast<int>(Q.theta * 2 / PI()) * PI() / 2) != 0) {
        r_x = P.x / Q.r * cos(Q.theta);
        r_y = P.y / Q.r * sin(Q.theta);
    } else {
        cout << "Cant use divide because theta = nPI, where n is an integer. Zero division error occuers. 717 indicates error occured." << endl;
    }
    return cartesian(r_x, r_y);
}
cartesian subtract(cartesian P, polar Q) {
    float r_x, r_y;

    r_x = P.x - Q.r * cos(Q.theta);
    r_y = P.y - Q.r * sin(Q.theta);

    return cartesian(r_x, r_y);
}

int main() {
    cartesian cart(3.0, 4.0), cart1(1.0, 2.5);
    polar pol(5, (PI() / 2));

    //  //*** Demonstration of part a of the question ***
    cout << "Part a output" << endl;
    cart1.display_co_ordinates();
    cart1.add(pol);  // Adding the Cartesian and polar coordinates
    cart1.display_co_ordinates();
    cout << endl;

    //  //*** Demonstration of part b of the question. ***
    cout << "Part c output" << endl;
    if (pol.is_greater_than(cart) == 1) {
        cout << "Magnitude of polar co-ordinate is greater than the cartesian." << endl;
    } else if (pol.is_greater_than(cart) == 0) {
        cout << "Magnitude of polar co-ordinate is equal to the cartesian." << endl;
    } else if (pol.is_greater_than(cart) == -1) {
        cout << "Magnitude of polar co-ordinate is less than the cartesian." << endl;
    }
    if (pol.lies_in_same_quadrant(cart)) {
        cout << "Polar and cartesian co-ordinates lie in the same quadrant." << endl;
    } else {
        cout << "Polar and cartesian co-ordinates doesn't lie in the same quadrant." << endl;
    }
    cout << endl;

    ///*** Demonstration of part b of the question ***
    cout << "Part b output" << endl;
    cart1 = multiply(cart, pol);
    cart1.display_co_ordinates();
    cart1 = divide(cart, pol);
    cart1.display_co_ordinates();
    cart1 = subtract(cart, pol);
    cart1.display_co_ordinates();
    cout << endl;

    return 0;
}

// /*
// OUTPUT
// Part a output
// (x , y) = (1.00 , 2.50)
// (x , y) = (1.00 , 7.50)

// Part c output
// Magnitude of polar co-ordinate is equal to the cartesian.
// Polar and cartesian co-ordinates lie in the same quadrant.

// Part b output
// (x , y) = (0.00 , 20.00)
// Cant use divide because theta = nPI, where n is an integer. Zero division error occuers. 717 indicates error occured.
// (x , y) = (717.00 , 717.00)
// (x , y) = (3.00 , -1.00)// */