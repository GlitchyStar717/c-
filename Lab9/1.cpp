//1.cpp
//using template function

#include<iostream>

using namespace std;

template <class T>
T sum(T array[4], int count){
    int i;
    T sum=0;
    for (i=0;i<count;i++){
        sum += array[i];
    }
    return sum;
}

int main(){

    int arr1[4] = {1,2,3,4};
    double arr2[6] = {1.2,2.4,3.6,4.8,6,7.2};
    double arr3[4] = {2.1f,4.2f,6.3f,8.4f};

    cout<< "Sum of the integer array is : "<<sum(arr1,4)<<endl;
    cout<< "Sum of the integer array is : "<<sum(arr2,6)<<endl;
    cout<< "Sum of the integer array is : "<<sum(arr3,4)<<endl;

    return 0;
}