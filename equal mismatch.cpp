// equal mismatch.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<algorithm>
#include<iterator>
#include<array>

using std::array;
using std::ostream_iterator;
using std::copy;
using std::cout;
using std::endl;
using std::equal;
using std::mismatch;
using std::lexicographical_compare;
using std::cbegin;
using std::cend;
int main()
{
    const int SIZE{ 10 };
    array<int, SIZE>a1{ 1,2,3,4,5,6,7,8,9,10 }; 
    array<int, SIZE>a2(a1);
    array<int, SIZE>a3{ 1,2,3,4,1000,6,7,8,9,10 };
    
    ostream_iterator<int>output{ cout," " };
    cout << "Array a1 contains: ";
    copy(a1.cbegin(), a1.cend(), output);
    cout << "\nArray a2 contains: ";
    copy(a2.cbegin(), a2.cend(), output);
    cout << "\nArray a3 contains: ";
    copy(a3.cbegin(), a3.cend(), output);

    bool result{ equal(a1.cbegin(),a1.cend(),a2.cbegin(),a2.cend()) };
    cout << "\n\na1 " << (result ? "is " : "is not ") << "equal to a2";
    result=equal(a1.cbegin(),a1.cend(),a3.cbegin(),a3.cend());
    cout << "\na1 " << (result ? "is " : "is not ") << "equal to a3";
    
    auto location=mismatch(a1.cbegin(), a1.cend(), a3.cbegin(), a3.cend()) ;
    cout << "\n\na1 and a3 are different at location" << (location.first - a1.cbegin())
        << "\nwhere a1 contains " << *(location.first)
        << " and a3 contains " << *(location.second)
        <<"\n\n";

    char c1[SIZE]{ "HELLO" };
    char c2[SIZE]{ "BYEBYE" };
    cout << "c1: "<<c1;
    cout << "\nc2: " << c2;
    
    result = lexicographical_compare(cbegin(a1), cend(a1), cbegin(a3), cend(a3));
    cout << "\nc1 " << (result ? "is less than " : "is greater than or equal to ") << "c2";
}

