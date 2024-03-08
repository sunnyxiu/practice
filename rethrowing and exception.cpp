// rethrowing and exception.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<exception>

using std::cout;
using std::cin;
using std::exception;

void throwException() {
    try {
        cout << "  Function throwException throws an exception\n";
        throw exception{};
    }
    catch (const exception&) {
        cout << "  Exception handled in funcion throwException"
            << "\n  Function throwException rethrow exception";
        throw;
    }
    cout << "this should not be printed";
}

int main()
{
    try {
        cout << "\nmain invokes function throwException\n";
        throwException();
        cout << "this should not be printed\n";
    }
    catch (const exception&) {
        cout << "\n\nException handled in main\n";
    }
    
    cout << "Program control continues after catch in main\n";
}

