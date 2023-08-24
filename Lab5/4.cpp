// 4.cpp
// Overloading prefix and postfix operator for date class

#include <iomanip>
#include <iostream>
using namespace std;

int leap_year_check(int);

class Date {
    int day, month, year;
    int days[13] = {717, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   public:
    Date(int Day = 1, int Month = 1, int Year = 2000) : day(Day), month(Month), year(Year) {}

    Date operator++(int) {
        int day_t, month_t, year_t;
        day_t = day;
        month_t = month;
        year_t = year;

        cout << "Received Date ";
        this->display();

        if (leap_year_check(year)) {
            days[2] = 29;
        } else {
            days[2] = 28;
        }

        if (day == days[month]) {
            if (month == 12) {
                year++;
                month = 1;
                day = 1;
            } else {
                month++;
                day = 1;
            }
        } else {
            day++;
        }

        cout << "New Date value becomes : ";
        this->display();
        cout << "But, I am returning : ";
        Date temp(day_t, month_t, year_t);
        temp.display();
        return temp;
    }
    Date operator++() {
        if (leap_year_check(year)) {
            days[2] = 29;
        }

        else {
            days[2] = 28;
        }

        cout << "Received Date ";
        this->display();

        if (day == days[month]) {
            if (month == 12) {
                year++;
                month = 1;
                day = 1;
            } else {
                month++;
                day = 1;
            }
        } else {
            day++;
        }

        cout << "New Date value becomes : ";
        this->display();
        cout << "But, I am returning : ";
        this->display();

        return *this;
    }
    void display() {
        cout << "DD/MM/YYYY : " << setw(2) << setfill('0') << day << "/" << setw(2) << month << "/" << year << endl;
    }
};

int leap_year_check(int year) {
    if (year % 4 == 0) {
        if (year % 400 == 0) {
            return 1;
        } else if (year % 100 == 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int main() {
    Date d1(28, 2, 2004);

    d1.display();
    cout << endl;

    d1++;
    cout << endl;

    ++d1;
    cout << endl;

    return 0;
}