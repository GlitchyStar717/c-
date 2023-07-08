//.cpp
//

#include<iostream>

using namespace std;

class vector{
    private:
        float x,y,z;
    public:
        vector(int a=0, int b=0, int c=0){
            x=a; y=b; z=c;
        }
        vector add(vector v){
            vector out;
            out.x = x + v.x;
            out.y = y + v.y;
            out.z = z + v.z;
            return out;
        }
        float dot(vector v){
            float result;
            result =  (x * v.x) + (y * v.y) + (z * v.z);
            return result;
        }
        vector cross(vector v){
            vector out;
            out.x = (y * v.z) - (z * v.y);
            out.y = (z * v.x) - (x * v.z);
            out.z = (x * v.y) - (y * v.x);
            return out;
        }
        void displayVector(){
            cout << x << "i + " << y << "j + " << z << "k\n";
        }

};

int main(){
    float dotProduct;
    vector A(1,2,4), B(2,6,9);
    vector C;
    C = A.add(B);
    C.displayVector();

    dotProduct = A.dot(B);
    cout << "Dot product is : " << dotProduct << endl;
    
    vector E;
    E = A.cross(B);
    E.displayVector();
    return 0;
}