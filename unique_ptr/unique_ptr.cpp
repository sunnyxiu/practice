// unique_ptr.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include"Integer.h"
#include <iostream>
#include<memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
int main()
{
    cout << "Creating a unique_ptr object that points to an Integer\n";
    unique_ptr<Integer> integerPtr{ make_unique<Integer>(7) };
    cout << "\nUsing the unique_ptr to set the Integer\n";
    integerPtr->setInteger(5);
    cout << "Integer after setInteger: " << (*integerPtr).getInteger() 
        << "\n\nTerminating program" << endl;
}


