
#include<iomanip>
#include <iostream>
using std::setw;
using std::cout;
unsigned long factorial(unsigned long a) {
    if (a <= 1) { return 1; }
    a = a * factorial(a - 1);
    return a;
}

int main()
{
    //n!=n*(n-1)!
    /*
    int total{1};
    for (unsigned int counter{ 1 }; counter <= 5; counter++) {
        total *= counter;
    }
    */
    
    for (int num{ 1 }; num <= 10; num++) {
        cout << setw(2)<<num << "! = " << setw(10)<<factorial(num)<<std::endl;
    }
    
}

