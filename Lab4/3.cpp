//3.cpp
//constructor and destructor use

#include<iostream>
#include<cstring>

using namespace std;

class record{
    private:
        int dept_id;
        char dept_name[4];
    public:
        record(const char input[] = "BCT", int ID = 0){
            strcpy(dept_name,input);
            dept_id = ID;
            cout<<"Object "<<dept_id<<" of department "<< dept_name<<" was created. \n";
        }
        ~record(){
            cout<<"Object "<<dept_id<<" goes out of scope.\n";
        }
};

int main(){

    record r1("BEI", 1),r2("BCT",0),r3("BCE",10);

}