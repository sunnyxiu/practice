// set operations.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<iterator>

using std::array;
using std::vector;
using std::ostream_iterator;
using std::includes;
using std::set_difference;
using std::set_intersection;
using std::set_symmetric_difference;
using std::cout;
using std::endl;
using std::set_union;

int main()
{
    const size_t SIZE10{ 10 };
    const size_t SIZE5{ 5 };
    array<int, SIZE10> a1{ 2,3,5,6,7,8,9,10,12,14 };
    array<int, SIZE5>a2{ 2,3,6,8,9 };
    array<int, SIZE5>a3{ 1,4,5,8,9 };
    ostream_iterator<int>output{ cout," " };

    cout << "a1 contains:\n";
    copy(a1.cbegin(), a1.cend(), output);
    cout << "\n\na2 contains:\n";
    copy(a2.cbegin(), a2.cend(), output);
    cout << "\n\na3 contains:\n";
    copy(a3.cbegin(), a3.cend(), output);

    if (includes(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend())) {
        cout << "\n\na1 includes a2";
    }
    else {
        cout << "\n\na1 doesn't include a2";
    }

    array<int,SIZE5> result1;
    auto endLocation = set_difference(a2.cbegin(), a2.cend(), a3.cbegin(), a3.cend(), result1.begin());
    cout << "\n\nresult1 after set_difference of a2 and a3:\n";
    copy(result1.begin(), endLocation, output);

    array<int, SIZE5> result2;
    endLocation = set_intersection(a2.cbegin(), a2.cend(), a3.cbegin(), a3.cend(), result2.begin());
    cout << "\n\nresult2 after set_intersection of a2 and a3:\n";
    copy(result2.begin(), endLocation, output);

    array<int, SIZE5 + SIZE10>result3;
    auto endLocation2 = set_union(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend(), result3.begin());
    cout << "\n\nresult3 after set_union of a1 and a2:\n";
    copy(result3.begin(), endLocation2, output);

    array<int, SIZE5 + SIZE5>result4;
    auto endLocation3 = set_symmetric_difference(a2.cbegin(), a2.cend(), a3.cbegin(), a3.cend(), result4.begin());
    cout << "\n\nresult4 after set_symmetric_difference of a2 and a3:\n";
    copy(result4.begin(), endLocation3, output);

    cout <<endl;
}

