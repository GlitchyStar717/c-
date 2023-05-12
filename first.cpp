#include <iostream>
#include <iomanip>

using namespace std; 

int main(){
    int lexp=500, cexp=800, texp=1000;

    cout<< setw(11) << "LODGING" <<setw(8)<<lexp<<endl;

    cout<<setw(11)<< "CLOTHING" <<setw(8)<<cexp<<endl;

    cout<<setw(11)<< "TRAVELING" <<setw(8)<<texp<<endl;
    return 0;
}