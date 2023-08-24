#include <iostream>
namespace Big{
    int a=5, b=4;
}
namespace Small{
    int a=7, b=7;
}
using namespace Small;
int main(){
    std::cout<<Big::a;
    std::cout<<b;
}