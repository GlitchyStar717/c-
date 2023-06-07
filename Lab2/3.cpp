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
    cout<<"Give the number to be squared : "<<endl; 
    cin >> Square::num; 
    Square::fun(Square::num);
    cout<<"Give the number to be cubed : "<<endl; 
    cin >> Cube::num; 
    Cube::fun(Cube::num);

    return 0;
}