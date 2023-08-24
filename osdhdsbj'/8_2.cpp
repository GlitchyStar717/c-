#include <iostream>
#include <iomanip>
using namespace std;
/*
Write a program to create a user-defined manipulator that will format the output by setting 
the width, precision, and fill character at the same time by passing arguments.*/


class FormatOutput {
private:
    int width;
    int precision;
    char fillChar;

public:
    FormatOutput(int w, int p, char fill) : width(w), precision(p), fillChar(fill) {}
    friend ostream& operator <<(ostream &os, FormatOutput &f);
};

    ostream& operator <<(ostream &os, FormatOutput &f){
    os<<setfill(f.fillChar)<<setw(f.width)<<setprecision(f.precision)<<endl;
    os<< flush;
    return os;
}

int main() {
    double number = 1208.2187;
    FormatOutput f(12,5,'*');
    std::cout << f << number << std::endl;

    return 0;
}