//4.cpp
//To demonstrate the usefulness of member functions using classes for many objects

#include<iostream>
#include<cmath>

using namespace std;

inline float pi(){
    return 3.14159;
}

class circle{
    private:
        float radius;
        float area;
        float perimeter;
    public:
        void setRadius(float n){
            radius = n;
            area = pi()*(radius*radius);
            perimeter = pi()*(radius*2);
        }
        void displayArea(){
            cout<<"The area of the circle is : "<<area<<endl;
        }
        void displayPerimeter(){
            cout<<"The circumference of the circle is : "<<perimeter<<endl;
        }
        void displayRadius(){
            cout<<"The radius of the circle is : "<< radius<<endl;
        }
        void displayEverything(){
            displayRadius();
            displayPerimeter();
            displayArea();
            cout<<endl;
        }
        
};
class triangle{
    private:
        float a;
        float b;
        float c;
        float s;
        float p;
        float area;
    public:
        void setLength(float x, float y, float z){
            a = x;
            b = y;
            c = z;
            calcSemiPerimeter();
            calcPerimeter();
            calcArea();
        }
        void calcSemiPerimeter(){
            s = (a+b+c)/2;
        }
        void calcArea(){
            area = sqrt(s*(s-a)*(s-b)*(s-c));
        }
        void calcPerimeter(){
            p = 2*s;
        }
        void displayArea(){
            // calcArea();
            cout<<"The area of the triangle is : "<< area<<endl;
        }
        void displayPerimeter(){
            cout<<"The perimeter of the triangle is : "<< p<<endl;
        }
        void displaySemiPerimeter(){
            cout<<"The semi-perimeter of the triangle is : "<< s<<endl;
        }
        void displayLengths(){
            cout<<"The lengths a, b, c of the triangle are "<< a<<", "<<b<<" and "<<c<<" respectively.\n";
        }
        void displayEverything(){
            displayLengths();
            displaySemiPerimeter();
            displayPerimeter();
            displayArea();
            cout<<endl;
        }
};
class rectangle{
    private:
        float l;
        float b;
        float p;
        float area;
    public:
        void setLength(float x, float y){
            l = x;
            b = y;
            calcPerimeter();
            calcArea();
        }
        void calcPerimeter(){
            p = (l+b)*2;
        }
        void calcArea(){
            area = static_cast <float> (l)*b;
        }
        void displayArea(){
            cout<<"The area of the rectangle is : "<< area<<endl;
        }
        void displayPerimeter(){
            cout<<"The perimeter of the rectangle is : "<< p<<endl;
        }
        void displayLengths(){
            cout<<"The length and breadth rectangle are "<< l<<" and "<<b<<" respectively.\n";
        }
        void displayEverything(){
            displayLengths();
            displayPerimeter();
            displayArea();
            cout<<endl;
        }
};

int main(){

    triangle t1;
    circle c1;
    rectangle r1;

    t1.setLength(4, 5, 6);
    c1.setRadius(7);
    r1.setLength(2.1,8);

    t1.displayEverything();
    r1.displayEverything();
    c1.displayEverything();

    return 0;
}