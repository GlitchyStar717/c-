//6.cpp
//return the sum of two areas of land

#include<iostream>

using namespace std;

class Landmeasure{
    private:
        int ropani, aana, paisa, dam;
    public:
        void setData(float r, float a, float p, float d){
            ropani = r;
            aana = a;
            paisa = p;
            dam = d;
        }
        int returnDam(){
            return dam;
        }
        int returnPaisa(){
            return paisa;
        }
        int returnAana(){
            return aana;
        }
        int returnRopani(){
            return ropani;
        }
        void displayData(){
            cout << "The total land area is : "<<ropani<<" Ropanis, "<<aana<<" Aana, "<<paisa<<" Paisa and "<<dam<<" Dam.\n";
        }
};

void addLandArea(Landmeasure *l1, Landmeasure *l2, Landmeasure *l3){

    int dam, paisa, aana, ropani, add1, add2, add3, add4;
    
    add1 = (l1->returnDam() + l2->returnDam()) / 4;
    add2 = (l1->returnPaisa() + l2->returnPaisa()) / 4;
    add3 = (l1->returnAana() + l2->returnAana()) / 16;

    dam = (l1->returnDam() + l2->returnDam()) % 4 ;
    paisa = (l1->returnPaisa() + l2->returnPaisa() + add1) % 4 ;
    aana = (l1->returnAana() + l2->returnAana() + add2) % 16 ;
    ropani = l1->returnRopani() + l2->returnRopani() + add3 ;

    l3-> setData(ropani,aana,paisa,dam);

}

int main(){
    Landmeasure l1,l2,l3; 

    l1.setData(2,11,4,2);
    l2.setData(2,2,2,4);

    addLandArea(&l1,&l2,&l3);
    l3.displayData();

}
