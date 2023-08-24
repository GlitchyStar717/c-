// 3.cpp
// overloading comparison operators

#include <iostream>

using namespace std;

class polar {
   private:
    int r;
    float theta;

   public:
    polar(float R = 0, float Theta = 0) : r(R), theta(Theta) {}

    void display_coordinates() {
        cout << "(r , theta) = (" << r << " , " << theta << ")" << endl;
    }

    int operator<(polar P) {
        if (r < P.r) {
            return 1;
        } else {
            return 0;
        }
    }
    int operator>(polar P) {
        if (r > P.r) {
            return 1;
        } else {
            return 0;
        }
    }
    int operator<=(polar P) {
        if (r <= P.r) {
            return 1;
        } else {
            return 0;
        }
    }
    int operator>=(polar P) {
        if (r >= P.r) {
            return 1;
        } else {
            return 0;
        }
    }
    int operator==(polar P) {
        if (r == P.r) {
            return 1;
        } else {
            return 0;
        }
    }
};

int main() {
    polar P(2, 3.14159), Q(1, 1.5068);

    cout << "P has co-ordinates ";
    P.display_coordinates();
    cout << "Q has co-ordinates ";
    Q.display_coordinates();
    if (P < Q) {
        cout << "P is less than Q" << endl;
    }
    if (P > Q) {
        cout << "P is greater than Q" << endl;
    }
    if (P <= Q) {
        cout << "P is less than or equal to Q" << endl;
    }
    if (P >= Q) {
        cout << "P is greater than or equal to Q" << endl;
    }
    if (P == Q) {
        cout << "P is equal to Q" << endl;
    }

    return 0;
}

// /*
// OUTPUT
// P has co-ordinates (r , theta) = (2 , 3.14159)
// Q has co-ordinates (r , theta) = (1 , 1.5068)
// P is greater than Q
// P is greater than or equal to Q
// */