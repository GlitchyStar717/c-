#include <iostream>

class ComplexNumber {
protected:
    double real;
    double imaginary;

public:
    ComplexNumber (int x=0, int y=0){
        real = x;
        imaginary = y;
    }  
    // void enterComplexNumber() {
    //     std::cout << "Enter real part: ";
    //     std::cin >> real;
    //     std::cout << "Enter imaginary part: ";
    //     std::cin >> imaginary;
    // }

    void displayComplexNumber() const {
        std::cout << "Complex Number: " << real << " + " << imaginary << "i" << std::endl;
    }

    double getRealPart() const {
        return real;
    }

    double getImaginaryPart() const {
        return imaginary;
    }
};

class DerivedComplexNumber : public ComplexNumber {
    int x,y;
public:
    ComplexNumber addComplexNumber() {
        
        std::cout << "Enter real part: ";
        std::cin >> ComplekxNumer::real;
        std::cout << "Enter imaginary part: ";
        std::cin >> ComplexNumber::imaginary;

        x = real + ComplexNumber::real;
        y= real + ComplexNumber::imaginary;
        ComplexNumber c1(x,y);



        return c1;
    }
    void displaysum() const {
        std::cout << "Sum: " << x << " + " << y << "i" << std::endl;
    }
};

class ComplexCalculator {
public:
    static void calculateDifference(const ComplexNumber& base, const DerivedComplexNumber& derived) {
        double diffReal = derived.getRealPart() - base.getRealPart();
        double diffImaginary = derived.getImaginaryPart() - base.getImaginaryPart();
        std::cout << "Difference: " << diffReal << " + " << diffImaginary << "i" << std::endl;
    }
};

int main() {
    ComplexNumber base;
    base.enterComplexNumber();
    base.displayComplexNumber();

    DerivedComplexNumber derived, d2;
    derived.enterComplexNumber();
    derived.displayComplexNumber();

    d2 = derived.addComplexNumber();
    d2.displaysum();

    ComplexCalculator::calculateDifference(base, derived);

    return 0;
}
