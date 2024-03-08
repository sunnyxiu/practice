// algorithms lower_bound, upper_bound, equal_range.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<algorithm>
#include<iterator>
#include<array>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::array;
using std::lower_bound;
using std::upper_bound;
using std::equal_range;
using std::copy;

int main()
{
    const size_t SIZE{ 10 };
    array<int, SIZE>a{ 1,2,2,3,3,6,6,6,8,9 };
    ostream_iterator<int> output{ cout," " };

    cout << "array a contains:\n";
    copy(a.cbegin(), a.cend(), output);

    auto location = lower_bound(a.cbegin(), a.cend(), 5);
    cout << "\n\nLower_bound of 5 is element " << (location - a.cbegin()) << " of array a";
    
    location = upper_bound(a.cbegin(), a.cend(), 5);
    cout << "\n\nUpper_bound of 5 is element " << (location - a.cbegin()) << " of array a";

    auto locaPair = equal_range(a.cbegin(), a.cend(), 5);
    cout << "\n\nLower_bound of 5 is element " << (locaPair.first - a.cbegin()) << " of array a";
    cout << "\n\nUpper_bound of 5 is element " << (locaPair.second - a.cbegin()) << " of array a";
    
    cout<<endl;
}

