#include <iostream>
#include"TimeByThisPtr.h"

using std::cout;

int main()
{
    Time t;
    cout<<"Time t after initialization: "<<t.toString()<<std::endl;
    cout<<"Time t after setting time by cascaded member function calls:"<<
        t.setHour(10).setMinute(30).setSecond(52).toString();

}


