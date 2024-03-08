// algorithm.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<cstdlib>


int main()
{
    int q{ 0 };
    int a;
    unsigned int d;
    std::cin >> a >> d;
    unsigned int r = abs(a);
    while (r >= d) {
        r -= d;
        q++;
    }
    if (a < 0 && r == 0) {
        q = -1*q;
    }
    if (a < 0 && r>0) {
        r = d - r;
        q = -1-q;
    }
        
    std::cout << "(" << q << "," << r << ")";


}


