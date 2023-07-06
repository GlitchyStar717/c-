//5.cpp
//relation between const and non_const objects and member functions

#include<iostream>

using namespace std;

class data{
    private:
        int id;
        static int no_of_data;
    public:
        data(){
            id = no_of_data++;
            cout<< "Object" << id << " was created.\n";

        };
        void const_display_value() const{
            cout << "Data " << id << " was accessed.\n";
        }
        void display_value(){
            cout << "Data " << id << " was accessed.\n";
        }
};

int data::no_of_data = 1;

int main(){

    const data d1,d2;
    data d3,d4;

    d1.const_display_value();
    // d2.display_value();

    d3.const_display_value();
    d4.display_value();

    return 0;
}