//2.cpp
//

#include<iostream>

using namespace std;

class number{
    private:
        int num;
    public:
        void checkPrime(){

            int i = 0, count = 0;
            for (i=1; i<=num; i++){
                if(num % i == 0){
                    count++;
                }

            } 
            if (count > 2){
                cout<<num<<" is composite.\n";
            }
            else{
                cout<<num<<" is prime.\n";
            }
        }

        void storeValue(int n){
            num = n;
        }
};

int main(){

    char loop = 'y';
    number n;
    int temp;

    while((loop == 'y' || loop == 'y') && !(loop == 'n' || loop == 'N')){

        cout<<"Enter a number : ";
        cin>>temp;
        n.storeValue(temp);
        n.checkPrime();

        cout<<"Do you want to try for another number ? (y/n) ";
        cin>>loop;
    }

    return 0;
}