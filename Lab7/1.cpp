// 1.cpp
// To use virtual function for assigning address of child object to pointer of base class

#include <iostream>
#define PI 3.14159
using namespace std;

class Shape {
   private:
    float area = 717;
    char name[10] = "Universal";

   public:
    virtual float get_area() {
        return area;
    }

    virtual void display() {
        cout << "The shape is: " << name << endl;
    }
};

class Rectangle : public Shape {
   private:
    float area;
    float length, breadth;
    char name[10] = "Rectangle";

   public:
    Rectangle(float l = 0, float b = 0) : length(l), breadth(b) {}
    float get_area() {
        return length * breadth;
    }
    void display() {
        cout << "The shape is: " << name << endl;
    }
};
class Circle : public Shape {
   private:
    float area;
    float radius;
    char name[10] = "Circle";

   public:
    Circle(float r = 0) : radius(r) {}
    float get_area() {
        return PI * radius * radius;
    }
    void display() {
        cout << "The shape is: " << name << endl;
    }
};
class Trapezoid : public Shape {
   private:
    float area;
    float a, b, h;
    char name[10] = "Trapezoid";

   public:
    Trapezoid(float x = 0, float y = 0, float z = 0) : a(x), b(y), h(z) {}
    float get_area() {
        return h * (a + b) / 2;
    }
    void display() {
        cout << "The shape is: " << name << endl;
    }
};

int main() {
    float var;
    Shape *shptr;
    Rectangle r1(10, 40);
    Circle c1(4);
    Trapezoid t1(4, 6, 2);

    cout << "Rectangle" << endl;
    shptr = &r1;
    cout << shptr->get_area() << endl;
    shptr->display();

    cout << "Circle" << endl;
    shptr = &c1;
    cout << shptr->get_area() << endl;
    shptr->display();

    cout << "Trapezoid" << endl;
    shptr = &t1;
    cout << shptr->get_area() << endl;
    shptr->display();

    return 0;
}

/*
OUTPUT
Rectangle
400
The shape is: Rectangle
Circle
50.2654
The shape is: Circle
Trapezoid
10
The shape is: Trapezoid
*/