// replace.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<algorithm>
#include<iterator>
#include<array>

using std::endl;
using std::cout;
using std::copy;
using std::ostream_iterator;
using std::replace;
using std::replace_if;
using std::replace_copy;
using std::replace_copy_if;
using std::array;

int main()
{
    const size_t SIZE{ 10 };
    array<int, SIZE>init{ 1,3,4,6,9,3,10,11,10,9 };
    array<int, SIZE>a1(init);
    ostream_iterator<int> output{ cout," " };
    
    cout << "a1 before replace 10s with 100s:\n";
    copy(a1.cbegin(), a1.cend(), output);

    cout << "\na1 after replace 10s with 100s:\n";
    replace(a1.begin(), a1.end(), 10, 100);
    copy(a1.cbegin(), a1.cend(), output);

    array<int, SIZE>a2(init);
    cout << "\n\na2 before replace 10s with 100s and copy to c1:\n";
    copy(a2.cbegin(), a2.cend(), output);

    array<int, SIZE>c1{ 0 };
    cout << "\nc1 after copy from a2 with 10s replaced by 100s:\n";
    replace_copy(a1.cbegin(), a1.cend(), c1.begin(), 10, 100);
    copy(c1.cbegin(), c1.cend(), output);

    array<int, SIZE>a3(init);
    cout << "\n\na3 before replace elements larger than 9 with 100s:\n";
    copy(a3.cbegin(), a3.cend(), output);

    cout << "\na3 after replace elements larger than 9 with 100s:\n";
    replace_if(a3.begin(), a3.end(),
        [](auto x) {return (x > 9); },100);
    copy(a3.cbegin(), a3.cend(), output);

    array<int, SIZE>a4(init);
    cout << "\n\na4 before replace elements larger than 9 with 100s and copy to c2:\n";
    copy(a4.cbegin(), a4.cend(), output);

    cout << "\nc2 after copy from a4 replaced elements alrger than 9 with 100s:\n";
    array<int, SIZE>c2{ 0 };
    replace_copy_if(a4.cbegin(), a4.cend(), c2.begin(),
        [](auto x) {return(x > 9); }, 100);
    copy(c2.cbegin(), c2.cend(), output);

}


