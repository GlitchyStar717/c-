#include<iostream>
using namespace std;
class demo{
    private:
        int x;
        int y;
    public:
        demo(int X, int Y): y(x), x(X){}
        void display(){
            cout<<x<<endl<<y<<endl;
        }
};

int main(){
    demo d1(4,5);
    d1.display();
}