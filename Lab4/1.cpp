//1.cpp
//Constructor use by creating Time class

#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

class Time{
    private:
        int hours, minutes, seconds;
    public:
        Time( int hh=0, int mm=0, int ss=0){
            hours = hh; minutes = mm; seconds = ss;
    }
    Time add(Time t){
        int sec_overflow, min_overflow;
        Time out_t;
        out_t.seconds = (seconds+t.seconds) % 60;
        sec_overflow = (seconds+t.seconds) / 60;
        out_t.minutes = (minutes+t.minutes+sec_overflow) % 60;
        min_overflow = (minutes+t.minutes+sec_overflow) / 60;
        out_t.hours = (hours+t.hours+min_overflow) % 24;
        return out_t;
    }
    void display_in_12(){
        char meridian[] = "am";
        if (hours == 0) hours += 12;
        if (hours > 12) { 
            strcpy(meridian,"pm");
            hours -= 12 ;
        }
        cout << "In 12 hours format: " << setw(2) << setfill('0') << hours << ":"<< setw(2) << setfill('0')  << minutes << ":" << setw(2) << setfill('0') << seconds << " " << meridian << endl;
    }
    void display_in_24(){
        cout << "In 24 hours format: " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
    }
};

int main(){

    Time t1(7,8,9), t2(3,4,5),t3;
    t1.display_in_12();
    t2.display_in_24();
    t3.display_in_24();

    t3 = t1.add(t2);

    t3.display_in_12();

    return 0;
}