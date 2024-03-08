// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include"Stack.h"
#include<string>

using std::string;
using std::cout;
using std::endl;

template <typename T>
void testStack(
    Stack<T>& stack,
    size_t stackSize, 
    const T& value, 
    const T& increment, 
    const string& stackName) {
    cout << "Pushing elements onto " << stackName<<endl;

    T pushValue{ value };

    for (size_t i{ 0 }; i < stackSize; i++) {
        stack.push(pushValue);
        cout << pushValue << " ";
        pushValue += increment;
    }

    cout << "\n\nPopping elements from " << stackName << endl;

    while (!stack.isEmpty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;

    cout << stackName << " is empty, cannot pop.\n";

    cout << endl;
}


int main()
{
    //create a stack of double
    Stack<double> doubleStack;
    const size_t doubleStackSize{ 5 };
    double doubleValue{ 1.1 };

    testStack(doubleStack, doubleStackSize, doubleValue, 1.1, "doubleStack");
    
    //create a stack of integer
    Stack<int> intStack;
    const size_t intStackSize{ 10 };
    int intValue{ 1 };

    testStack(intStack, intStackSize, intValue, 1, "intStack");
    
}


