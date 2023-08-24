// 1.cpp
//[] Overloading by making a class that accpets floats as index by converting the float to integer

#include <iostream>
using namespace std;

class Data {
   private:
    int *member;
    int member_size;

   public:
    Data(initializer_list<int> list) {
        int i = 0;
        member_size = list.size();
        member = new int[member_size];
        for (int val : list) {
            member[i++] = val;
        }
    }
    Data() {
        member_size = 1;
        member = new int[member_size];
        member[0] = 0;
    }
    void function() {
        cout << member << endl;
    }
    int operator[](float number);
    ~Data() {
        delete[] member;
        cout << "Object deleted." << endl;
    }
};

int Data::operator[](float number) {
    int index = static_cast<int>(number);
    if (index <= member_size - 1) {
        return member[index];
    } else {
        cout << "List not initiated." << endl;
        return 717;
    }
}

int main() {
    Data d1({5, 10, 20, 15});
    float input = 2.4, output;
    output = d1[input];
    cout << output << endl;
    ;
}


/*
OUTPUT

20
Object deleted.
*/