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
            SN = ++no_of_items;
            cout<< "Object with SN " << SN << " was created.\n";
        };
        static void show_no_of_objects(){
            cout << "The Number of Objects created are : " << no_of_items << endl;;
        }

};

int items::no_of_items = 0;

int main(){

    items i1, i2, i3;
    items::show_no_of_objects();
    items i4;
    i4.showNoOfObjects();

    return 0;
}