// basic searching and sorting algorithms.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<array>
#include<iterator>
#include<algorithm>

using std::cout;
using std::endl;
using std::array;
using std::ostream_iterator;
using std::copy;
using std::find;
using std::find_if;
using std::sort;
using std::binary_search;
using std::all_of;
using std::any_of;
using std::none_of;
using std::find_if_not;

int main()
{
    const size_t SIZE{ 10 };
    array<int, SIZE>a{ 3,7,10,11,9,5,12,4,6,12 };
    ostream_iterator<int>output{ cout," " };
    cout << "array a contains:\n";
    copy(a.cbegin(), a.cend(), output);

    auto location = find(a.cbegin(), a.cend(), 10);
    if (location != a.cend()) {
        cout << "\n\nFound 10 in array a at location " << (location - a.cbegin());
    }
    else {
        cout << "\n\n10 not found";
    }

    auto greaterThan10=([](auto x) {return (x > 10); } );
    location = find_if(a.cbegin(), a.cend(), greaterThan10);
    if (location != a.cend()) {
        cout << "\n\nelement greater than 10 is found at location " << (location - a.cbegin());
    }
    else {
        cout << "\n\nelement greater than 10 is not found";
    }

    sort(a.begin(), a.end());
    cout << "\n\nAfter sorting, array a contains:\n";
    copy(a.cbegin(), a.cend(), output);

    if (binary_search(a.cbegin(), a.cend(), 12)) {
        cout << "\n\n12 was found";
    }
    else {
        cout << "\n\n12 was not found";
    }

    if (all_of(a.cbegin(), a.cend(), greaterThan10)) {
        cout << "\n\nall of elements in array a are greater than 10";
    }
    else {
        cout << "\n\nsome elements in array a are not greater than 10";
    }

    if (any_of(a.cbegin(), a.cend(), greaterThan10)) {
        cout << "\n\nthere exists element in array a greater than 10";
    }
    else {
        cout << "\n\nthere is no element in array a greater than 10";
    }

    if (none_of(a.cbegin(), a.cend(), greaterThan10)) {
        cout << "\n\nnone of elements in array a is greater than 10";
    }
    else {
        cout << "\n\nthere is element in array a greater than 10";
    }

    location = find_if_not(a.cbegin(), a.cend(), greaterThan10);
    if (location != a.cend()) {
        cout << "\n\nelement not greater than 10 is found at location " << (location - a.cbegin());
    }
    else {
        cout << "\n\nall elements are greater than 10";
    }

    cout << endl;

    
}

