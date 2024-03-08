// lambda expression.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<algorithm>
#include <iostream>
#include<array>
#include<iterator>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::array;
using std::for_each;
using std::copy;

void timesTwo(int value) {
    cout<<value*2<<" ";
}

int main()
{
    const size_t SIZE{ 4 };
    array<int, SIZE> values{1, 2, 3, 4};
    ostream_iterator<int> output{ cout," " };
    cout << "values contain: ";
    copy(values.cbegin(), values.cend(), output);
    cout << "\nDisplay each element multiplied by two: ";

    for_each(values.cbegin(), values.cend(),
        [](auto i) {cout << i * 2 << " "; });

    int sum{ 0 };
    for_each(values.cbegin(), values.cend(), [&sum](int i) {sum += i; });

    cout << "\nSum of values's elements is: " << sum << endl;
}


