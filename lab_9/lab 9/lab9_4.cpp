#include <iostream>
using namespace std;
class MyException {
private:
    string message;

public:
    MyException(string msg) : message(msg) {}

    string myerror() const {
        return message;
    }
};

int main() {
    try {
        int num1, num2;
        cout << "Enter the numerator: ";
        cin >> num1;
        cout << "Enter the denominator: ";
        cin >> num2;

        if (num2 == 0) {
            throw MyException("Division by zero");
        }

        double result = static_cast<double>(num1) / num2;
        cout << "Result: " << result << endl;
    } catch (MyException e) {
        cout << "ERROR: " << e.myerror() << endl;
    }

    return 0;
}
