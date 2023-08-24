// 2.cpp
// using

#include <iostream>

using namespace std;

class Person {
protected:
    string name, address, phone;

public:
    Person(){}
    Person(const char Name[], const char Address[], const char Phone[]) {
        name = Name;
        address = Address;
        phone = Phone;
    }
    virtual void display_attributes() {
        cout<<endl;
        cout << "The person's name is " << name << ".\nHe lives in " << address << ".\nHis telephone number is : " << phone << endl;
    }
};

class Student : virtual public Person {
protected:
    string institution;

public:
    Student(const char Name[], const char Address[], const char Phone[], const char Institution[]) : Person(Name, Address, Phone) {
        institution = Institution;
    }
    void display_attributes() {
        Person::display_attributes();
        cout<<endl;
        cout << name << " studies in " << institution << endl;
    }
};

class Employee : virtual public Person {
protected:
    string team, organization;

public:
    Employee(const char Name[], const char Address[], const char Phone[], const char Team[], const char Organization[]) : Person(Name, Address, Phone) {
        team = Team;
        organization = Organization;
    }
    void display_attributes() {
        cout<<endl;
        Person::display_attributes();
        cout << name << " works in " << organization << " in team " << team << endl;
    }
};

class Manager : public Student, public Employee {
private:
    int projects_handled;

public:
    Manager(const char Name[], const char Address[], const char Phone[], const char Team[], const char Organization[], const char Institution[], int Projects_Done) : Person(Name, Address, Phone), Employee(Name, Address, Phone, Team, Organization), Student(Name, Address, Phone, Institution) {
        projects_handled = Projects_Done;
    }
    void display_attributes() {
        cout<<endl;
        Student::display_attributes();
        Employee::display_attributes();
        cout << name << " has handled: " << projects_handled << " projects." << endl;
    }
};

int main() {
    Manager M1("Shashank", "Maharajgunj", "98634yyyyy", "Creative", "PDSC", "PulchowkCampus", 5);
    Employee E1("Lijan", "Tokha", "98634xxxxx", "CR", "Class");
    Student S1("Aaditya", "Basundhara", "98634zzzzz", "TC");
    E1.display_attributes();
    S1.display_attributes();
    M1.display_attributes();
    return 0;
}