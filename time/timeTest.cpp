#include <iostream>
#include<stdexcept>
#include"Time.h"
using std::cout;
using std::invalid_argument;

void displayTime(const string& message, const Time& time) {
    cout << message << "\nUniversal time: " << time.toUniversalString()
        << "\nStandard time: " << time.toStandardString()<<"\n\n";
}

int main()
{
    Time t1;
    unsigned int& hourRef{ t1.setHourRef(20) };
    displayTime("t1 after sethour by reference", t1);
    hourRef = 50;
    displayTime("t1 after sethour by reference", t1);
    
    

    

}

