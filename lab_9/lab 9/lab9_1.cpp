#include<iostream>

using namespace std;


template <class T>

T ret_sum(T *array,int count)

{
    T sum=0;

    for(int i=0; i<count; i++){
        sum += array[i];
    }

    // delete[] array;

    return sum;
}

int main()

{

    int a[4]= {1,2,3,4};

    double b[5]= {1.1,2.2,3.3,4.4,5.5};

    float c[5] = {1.5f, 2.5f, 3.5f, 4.5f, 5.5f};

    cout<<" Sum of elements of a: "<<ret_sum(a,4)<<endl;
    
    cout<<" Sum of elements of b: "<<ret_sum(b,5)<<endl;
    
    cout<<" Sum of elements of c: "<<ret_sum(c,5)<<endl;

    return 0;

}