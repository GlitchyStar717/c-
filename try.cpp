#include<iostream>
using namespace std;

int result_when_index_0();
int result_when_index_1();

class Array{
    int* arr, *arr2;
    int loop;
    public: 
        Array(const int Arr[], int count){
            int i, a=1, b=2,c;
            arr = new int[count];
            for (i=0; i<count-1; i++){
                arr[i]=Arr[i];
            } //No of possible combinations is a fibonacci
            for (i=0;i<count;i++){
                c=a+b;
                a=b;
                b=c;
            }
            arr2 = new int[c];

        }
        int find_max(){
            int t1,t2;
            t1 = result_when_index_0();
            t2 = result_when_index_1();
            if (t1>t2){
                return t2;
            }
            else{
                return t1;
            }
        }
                    friend int result_when_index_0(Array);
                    friend int result_when_index_1(Array);

};

int result_when_index_0(Array a1){
    return 0;
}

int main(){
    int a[3]={1,2,3};
    Array a1(a,3);
    return 0;

}