#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
/*
Write a program to demonstrate the use of different ios flags and functions to format the output.
Create a program to generate the bill invoice of a department store by using different formatting.*/

struct Item {
    string name;
    int quantity;
    float price;
};

class DepartmentStore

{
   private:
    Item items[3];

   public:
    DepartmentStore() {
        items[0] = {"Watch", 1, 6000.00};
        items[1] = {"Shirt", 2, 1000.00};
        items[2] = {"Shoes", 3, 4000.00};
    }

    void printInvoice() {
        float total = 0.0;

        cout << left << setw(15) << "Item" << right << setw(10) << "Quantity" << setw(10) << "Price" << setw(12) << "Total" << endl;

        for (int i = 0; i < 50; i++) {
            cout << "-";
        }
        cout << endl;
        for (Item& item : items) {
            float itemTotal = item.quantity * item.price;
            total += itemTotal;

            cout << left << setw(15) << item.name << right << setw(8) << item.quantity << setw(12) << fixed << setprecision(2) << item.price << setw(12) << fixed << setprecision(2) << itemTotal << endl;
        }

        for (int i = 0; i < 50; i++) {
            cout << "-";
        }
        cout << endl;
        cout << left << setw(41) << "Total" << setw(10) << fixed << setprecision(2) << total << endl;
    }
};

int main() {
    DepartmentStore store;
    int totalWidth = 12;
    string text = "Bill Invoice";
    cout <<"-------------------Bill Invoice-------------------" << endl;
    cout << setw((totalWidth + text.length()) / 2)<< setfill ('-') << text << setw(totalWidth - (totalWidth + text.length()) / 2)<<setfill('-') << "" << endl;
    store.printInvoice();

    return 0;
}
