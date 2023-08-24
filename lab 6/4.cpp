#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person() : name(""), age(0) {}

    void enterInfo() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
    }

    void printAddressUsingThis() const {
        std::cout << "Address of the object using this: " << this << std::endl;
    }
};

class Student : public Person {
public:
    void assignRecord() {
        enterInfo();
        std::cout << "Record assigned to student: " << name << ", Age: " << age << std::endl;
    }

    void printAddressUsingThis() const {
        std::cout << "Address of the object using this: " << this << std::endl;
    }
};

class Employee : public Person {
public:
    void assignRecord() {
        enterInfo();
        std::cout << "Record assigned to employee: " << name << ", Age: " << age << std::endl;
    }

    void printAddressUsingThis() const {
        std::cout << "Address of the object using this: " << this << std::endl;
    }
};

int main() {
    Person person1;
    Person person2;
    Student student1;
    Student student2;
    Employee employee1;
    Employee employee2;

    std::cout << "Address of person1: " << &person1 << std::endl;
    person1.printAddressUsingThis();

    std::cout << "Address of person2: " << &person2 << std::endl;
    person2.printAddressUsingThis();

    std::cout << "Address of student1: " << &student1 << std::endl;
    student1.printAddressUsingThis();

    std::cout << "Address of student2: " << &student2 << std::endl;
    student2.printAddressUsingThis();

    std::cout << "Address of employee1: " << &employee1 << std::endl;
    employee1.printAddressUsingThis();

    std::cout << "Address of employee2: " << &employee2 << std::endl;
    employee2.printAddressUsingThis();

    return 0;
}
