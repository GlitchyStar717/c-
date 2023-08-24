// 2.cpp
// new and delete overload

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Matrix {
   private:
    int **x;
    int x_size;

   public:
    Matrix(initializer_list<int> Xlist) {
        x_size = sqrt(Xlist.size());
        x = new int *[x_size];

        int i = 0, j = 0;

        for (i = 0; i < x_size; i++) {
            x[i] = new int[x_size];

            for (j = 0; j < x_size; j++) {
                x[i][j] = *(Xlist.begin() + 3 * i + j);
            }
        }
    }

    Matrix(int rank = 1, int fill = 7) {
        x_size = rank;
        x = new int *[x_size];
        int i, j;
        for (i = 0; i < x_size; i++) {
            x[i] = new int[x_size];
            for (j = 0; j < rank; j++) {
                x[i][j] = i+j;
            }
        }
    }

    void* operator new(size_t t, int size) {
        cout << "New memory allocated for object of Matrix is : " << t << endl;
        void *ptr = ::operator new(t + size);
        return ptr;
    }

    void operator delete(void *ptr) {
        cout << "Delete memory that was allocated for x" << endl;
        ::operator delete(ptr);
    }

    int size_getter() {
        return x_size;
    }

    void display() {
        int i, j;
        for (i = 0; i < x_size; i++) {
            for (j = 0; j < x_size; j++) {
                cout << setw(10) << x[i][j];
            }
            cout << endl;
        }
    }
    
    
    void set_value() {
        delete_x();

        cout << "Input the rank of the matrix : ";
        cin >> x_size;
        x = new int *[x_size];
        int i, j;
        for (i = 0; i < x_size; i++) {
            x[i] = new int[x_size];
            for (j = 0; j < x_size; j++) {
                x[i][j] = i+j;
            }
        }
    }

    // void set_Value(int* arr, int size) {

    //     delete_x();

    //     arr = new int[size];

    //     x_size = sqrt(size/sizeof(arr[0]));

    //     cout<<"reached point 1"<<endl;
    //     x = new int *[x_size];
    //     int i, j;
    //     for (i = 0; i < x_size; i++) {
    //         x[i] = new int[x_size];
    //         for (j = 0; j < x_size; j++) {
    //             x[i][j] = arr[ 3 * i + j];
    //         }
    //     }
    //     delete[] arr;
    // }


    
    // void set_Value(initializer_list<int> list) {

    //     cout<<"Reached here."<<endl;
    //     cout<<sqrt(list.size())<<endl;
    //     x_size = sqrt(list.size());
    //     delete_x();
    //     cout<<"reached point 1"<<endl;
        
    //     x = new int*[x_size];

    //     int i, j;
    //     for (i = 0; i < x_size; i++) {
    //         x[i] = new int[x_size];
    //         for (j = 0; j < x_size; j++) {
    //             x[i][j] = *(list.begin()+ 3 * i + j);
    //         }
    //     }


    //     cout<<"\n\n";
    //     for (int value : list){
    //         cout<<setw(4)<<value;
    //     }
    //     cout<<"hi"<<endl;


    // }

    void delete_x(){
        int i;
        for (i = 0; i < x_size; i++) {
            delete[] x[i];
        }
        delete[] x;
    }

    ~Matrix() {
        int i;
        cout << "Desctructor called." << endl;
        for (i = 0; i < x_size; i++) {
            delete[] x[i];
        }
        delete[] x;
    }
};

int main() {
    
    int var,i;
    cout<<"No of matrix you need : ";
    cin>> var;

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix *M1 = new (sizeof(Matrix)) Matrix;
    
    for(i=0;i<var;i++){
        M1[i].set_value();        
    }
    for(i=0;i<var;i++){
        M1[i].display();        
    }

    delete[] M1;

    
    // Matrix* M1 = new (sizeof(Matrix)) Matrix;
    // M1[0].set_Value({1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 13, 14});
    // M1[0].display();
    // delete[] M1;


    
    // int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 13, 14};
    // Matrix* M1 = new (sizeof(Matrix)) Matrix;
    // cout<<sizeof(arr2)<<endl;
    // M1[0].set_Value(&arr2[0], sizeof(arr2));
    // M1[0].display();
    // delete[] M1;




    // // Allocate memory for the Matrix object itself
    // void* rawMemory = ::operator new(sizeof(Matrix));
    // // Construct the Matrix object using placement new
    // M1 = new  Matrix(50, 4);
    // M1->display();
    // // Call the destructor explicitly (since we used placement new)
    // M1->~Matrix();
    // // Deallocate the memory for the Matrix object
    // ::operator delete(rawMemory);



}

/*
OUTPUT

New memory allocated for x is : 16
  1  2  3
  4  5  6
  7  8  9
Desctructor called.
Delete memory that was allocated for x
New memory allocated for x is : 16
  1  5
  2  0
Desctructor called.
Delete memory that was allocated for x
*/