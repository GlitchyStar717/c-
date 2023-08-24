// 2.cpp
// using

#include <iostream>

using namespace std;

class Person {
   protected:
    string name, address, phone;

   public:
    Person(string Name, string Address, string Phone) {
        name = Name;
        address = Address;
        phone = Phone;
    }
    virtual void display_all_attributes() {
        display_personal_attributes();
        cout<<endl;
    }
    virtual void display_personal_attributes() {
        cout << "The person's name is " << name << ".\nHe lives in " << address << ".\nHis telephone number is : " << phone << endl;
    }
};

class Student : virtual public Person {
   protected:
    string institution;

   public:
    Student(string Name, string Address, string Phone, string Institution) : Person(Name, Address, Phone) {
        institution = Institution;
    }
    void display_all_attributes() {
        Person::display_personal_attributes();
        display_academic_attributes();
        cout<<endl;
    }
    void display_academic_attributes() {
        cout << name << " studies in " << institution << endl;
    }
};

class Employee : virtual public Person {
   protected:
    string team, organization;

   public:
    Employee(string Name, string Address, string Phone, string Team, string Organization) : Person(Name, Address, Phone) {
        team = Team;
        organization = Organization;
    }
    virtual void display_all_attributes() {
        display_personal_attributes();
        display_working_attributes();
        cout<<endl;
    }
    void display_working_attributes() {
        cout << name << " works in " << organization << " in team " << team << endl;
    }
};

class Manager : public Student, public Employee {
   private:
    int projects_handled;

   public:
    Manager(string Name, string Address, string Phone, string Team, string Organization, string Institution, int Projects_Done) : Person(Name, Address, Phone), Employee(Name, Address, Phone, Team, Organization), Student(Name, Address, Phone, Institution) {
        projects_handled = Projects_Done;
    }
    void display_all_attributes() {
        Person::display_personal_attributes();
        Student::display_academic_attributes();
        Employee::display_working_attributes();
        display_managerial_attributes();
        cout<<endl;
    }
    void display_managerial_attributes() {
        cout << name << " has handled: " << projects_handled << " projects." << endl;
    }
};

int main() {
    Manager M1("Shashank", "Maharajgunj", "98634zzzzz", "Creative", "PDSC", "PulchowkCampus", 5);
    Employee E1("Lijan", "Tokha", "98634xxxxx", "CR", "Class");
    Student S1("Aaditya", "Basundhara", "98634yyyyy", "TC");
    E1.display_all_attributes();
    M1.display_all_attributes();
    S1.display_all_attributes();
    return 0;
}