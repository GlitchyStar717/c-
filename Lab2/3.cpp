//3.cpp
//to demonstrate namespace's functionality using two self declared namespaces Cube and Square..

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

namespace Cube{
    int num;
    void fun(int n){
        cout << (n*n*n) << " is the cube.\n";
    }
}

namespace Square{
    int num;
    void fun(int n){
        cout << (n*n) << " is the square.\n";
    }
}

int main(){
    Square::num = 12; 
    Cube::num = 14; 

    cout<<"The value stored in num of square numspace is : "<<Square::num<<endl;
    cout<<"The value stored in num of cube numspace is : "<<Cube::num<<endl;

    Square::fun(Cube::num);
    Cube::fun(Square::num);

    return 0;
}