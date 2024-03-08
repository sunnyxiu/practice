// swap.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<algorithm>
#include <iostream>
#include<iterator>
#include<array>

using std::cout;
using std::endl;
using std::swap;
using std::iter_swap;
using std::swap_ranges;
using std::array;
using std::ostream_iterator;

int main()
{
    const size_t SIZE{ 10 };
    array<int, SIZE> a {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array<int, SIZE> a2{ 21,22,23,24,25,26,27,28,29,30 };
    ostream_iterator<int>output{ cout," " };
    
    cout << "array a contains:\n";
    copy(a.cbegin(), a.cend(), output);

    cout << "\n\narray a2 contains:\n";
    copy(a2.cbegin(), a2.cend(), output);

    cout << "\n\nafter swap, array a contains:\n";
    swap(a[0], a[1]);
    copy(a.cbegin(), a.cend(), output);

    cout << "\n\nafter iter_swap, array a contains:\n";
    iter_swap(a.begin(), a.begin() + 1);
    copy(a.cbegin(), a.cend(), output);;

    cout << "\n\nafter swap_ranges, array a contains:\n";
    swap_ranges(a2.begin(), a2.begin() + 5, a.begin() + 5);
    copy(a.cbegin(), a.cend(), output);
    
    cout << "\n\nafter swap_ranges, array a2 contains:\n";
    copy(a2.cbegin(), a2.cend(), output);
    
    cout << endl;
}

