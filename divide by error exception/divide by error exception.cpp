// divide by error exception.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include"DivideByZeroException.h"
#include <iostream>
#include<stdexcept>

using std::cout;
using std::endl;
using std::cin;

double quotient(int numerator, int denominator) {
    if (denominator == 0) {
        throw DivideByZeroException{};
    }

    return (static_cast<double>(numerator) / denominator);
}

int main()
{
    int a;
    int b;

    cout << "Enter two integers (end-of-file to end): ";

    while (cin >> a >> b) {
        try {
            double result{ quotient(a,b)};
            cout << a << "/" << b << " = " << result;
        }
        catch (const DivideByZeroException& divideByZero) {
            cout << "Exception occurred: "<<divideByZero.what();
        }

        cout << "\n\nEnter two integers (end-of-file to end): ";
    }
    
    cout << endl;
}


