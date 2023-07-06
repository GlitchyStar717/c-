//6.cpp
//demonstration of static data member use

#include<iostream>

using namespace std;

class items{
    private:
        int SN;
        static int no_of_items;
    public:
        items(){
            SN = no_of_items++;
            cout<< "Object with SN " << SN << " was created.\n";

        };
};

int items::no_of_items = 1;

int main(){

    items i1,i2,i3;

    return 0;
}