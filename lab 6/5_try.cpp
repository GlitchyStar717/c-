#include <iostream>

class ComplexNumber {
protected:
    double real;
    double imaginary;

public:
    void enterComplexNumber() {
        std::cout << "Enter real part: ";
        std::cin >> real;
        std::cout << "Enter imaginary part: ";
        std::cin >> imaginary;
    }

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
public:
    void addComplexNumber(const ComplexNumber& other) {
        real += other.real;
        imaginary += other.imaginary;
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

    DerivedComplexNumber derived;
    derived.enterComplexNumber();
    derived.displayComplexNumber();

    derived.addComplexNumber(base);
    derived.displayComplexNumber();

    ComplexCalculator::calculateDifference(base, derived);

    return 0;
}