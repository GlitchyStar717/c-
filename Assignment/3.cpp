// 3.cpp
// Assignment operator overloading

#include <iostream>
using namespace std;

/* Demonstration of the classical problem with default copy constructor when data member is a pointer

class Book {
   private:
    int *price;

   public:
    Book(int x = 100) {
        price = new int[1];
        price[0] = x;
    }
    int price_getter() { return price[0]; }
    void price_setter(int x) { price[0] = x; }
    void display() {
        cout << "Price: " << price[0] << endl;
    }

    ~Book() {
        delete[] price;
        cout << "Desstructor called." << endl;
    }
};

int main() {
    Book b(1000);
    b.display();

    Book b2(2000);
    b2.display();

    b2 = b;

    b.price_setter(3000);
    b.display();
    b2.display();
}

OUTPUT:
Price: 1000
Price: 2000
Price: 3000
Price: 3000
Desstructor called.

Similar problem if we used the copy constructor as Book b2(b1); or Book b2 = b1;
*/

// When we use overloaded assignment operator

class Book {
   private:
    int *price;

   public:
    //To address the problem during construction time.
    Book(Book &another_book){
        price = new int[1];
        price[0] = another_book.price_getter();
    }

    void operator =(Book another_book){
        delete[] price;
        price = new int[1];
        price[0] = another_book.price_getter();
    }

    Book(int x = 100) {
        price = new int[1];
        price[0] = x;
    }
    int price_getter() { return price[0]; }
    void price_setter(int x) { price[0] = x; }
    void display() {
        cout << "Price: " << price[0] << endl;
    }

    ~Book() {
        delete[] price;
        cout << "Desstructor called." << endl;
    }
};

int main() {
    Book b(1000);
    b.display();

    Book b2(2000);
    b2.display();

    b2 = b;

    b.price_setter(3000);
    b.display();
    b2.display();

    b.~Book();
    b2.~Book();
}

/*
OUTPUT 

Price: 1000
Price: 2000
Desstructor called.
Price: 3000
Price: 1000
Desstructor called.
Desstructor called.
*/
