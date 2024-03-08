// bitset.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<bitset>
#include <iostream>
#include<string>
using std::string;
using std::bitset;
using std::cout;
using std::endl;

int main()
{
    bitset < 4> bits{ "1010" };
    bitset<4>bit2{ "0010" };
    cout << bits.count();
}


