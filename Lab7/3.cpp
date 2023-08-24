// 3.cpp
// Accessing bchild classes using base class' pointer

#include <iostream>
using namespace std;

class Student {
   protected:
    int roll_no;
    string name, address;

   public:
    Student(string Name = "XYZ", string Address = "---", int roll = 0) : name(Name), address(Address), roll_no(roll) {}
    virtual void display_attribute() {
        cout << name << " lives in " << address << ".\nHis roll no is : " << roll_no << ".\n";
    }
};

class Engineer : public Student {
   private:
    int days_survived;

   public:
    Engineer(string Name = "XYZ", string Address = "---", int roll = 0, int DaysSurvived = 500) : Student(Name, Address, roll), days_survived(DaysSurvived) {}
    void display_attribute() {
        cout << endl;
        Student::display_attribute();
        cout << name << " has survived " << days_survived << " days doing engineering." << endl;
    }
};

class Medical : public Student {
   private:
    int tobacco_consumed;

   public:
    Medical(string Name = "XYZ", string Address = "---", int roll = 0, int TobaccoConsumed = 500) : Student(Name, Address, roll), tobacco_consumed(TobaccoConsumed) {}
    void display_attribute() {
        cout << endl;
        Student::display_attribute();
        cout << name << " has consumed " << tobacco_consumed << " tobacco products when studying Medical." << endl;
    }
};

class Science : public Student {
   private:
    int papers_published;

   public:
    Science(string Name = "XYZ", string Address = "---", int roll = 0, int PapersPublished = 500) : Student(Name, Address, roll), papers_published(PapersPublished) {}
    void display_attribute() {
        cout << endl;
        Student::display_attribute();
        cout << name << " has published " << papers_published << " papers studying Science." << endl;
    }
};

int main() {
    int i;
    Student *Sptr[] = {
        new Engineer("Shashank", "Maharajgunj", 84, 500),
        new Medical("Anubhav", "India", 23, 300),
        new Science("Einstein", "Germany", 10, 112),
    };
    for (i = 0; i < 3; i++) {
        Sptr[i]->display_attribute();
    }
    for (i = 0; i < 3; i++) {
        delete Sptr[i];
    }
    return 0;
}

/*
OUTPUT
Shashank lives in Maharajgunj.
His roll no is : 84.
Shashank has survived 500 days doing engineering.

Anubhav lives in India.
His roll no is : 23.
Anubhav has consumed 300 tobacco products when studying Medical.

Einstein lives in Germany.
His roll no is : 10.
Einstein has published 112 papers studying Science.
*/