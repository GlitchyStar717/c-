//3.cpp
//constructor and destructor use

#include<iostream>
#include<cstring>

using namespace std;

class record{
    private:
        int dept_id;
        static int no_of_objects;
        char dept_name[4];
    public:
        record(const char input[] = "BCT"){
            strcpy(dept_name,input);
            dept_id = no_of_objects;
            cout<<"Object "<<no_of_objects<<" of department "<< dept_name<<" was created. \n";
            no_of_objects++;
        }
        ~record(){
            no_of_objects--; 
            cout<<"Object "<<no_of_objects<<" goes out of scope.\n";
        }
};

int record::no_of_objects = 0;

int main(){

    record r1("BEI"),r2,r3;

}