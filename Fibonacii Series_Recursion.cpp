// Fibonacii Series_Recursion.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using std::cout;
unsigned int fibonaciiRe(unsigned int);
void fibonaciiIt(unsigned int);
int main()
{//0 1 1 2 3 5 8
    //f(n)=f(n-1)+f(n-2)
    fibonaciiIt(5);

}

unsigned int fibonaciiRe(unsigned int num) {
    if ((0==num)||(1==num)) { return num; }
    else {
        num = fibonaciiRe(num - 1) + fibonaciiRe(num - 2);
        return num;
    }
}
void fibonaciiIt(unsigned int num) {
    int x{ 0 }, y{ 1 }, z{ 0 };
    for (int i{ 1 }; i <= num; i++) {
        cout << x << " ";
        z = x + y;
        x = y;
        y = z;
        
    }
}

