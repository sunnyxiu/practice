// Algorithms min, max, minmax.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<algorithm>
#include<array>
#include<iterator>

using std::cout;
using std::endl;
using std::array;
using std::ostream_iterator;
using std::min;
using std::max;
using std::minmax;
using std::minmax_element;
using std::copy;

int main()
{
    const size_t SIZE{ 10 };
    cout << "min(3,7) = " << min(3, 7);
    cout << "\nmax(3,7) = " << max(3, 7);
    cout << "\nmin('A','D') = " << min('A', 'D');
    cout << "\nmax('A','D') = " << max('A', 'D');
    cout << "\nmin(3,7) = " << minmax(3, 7).first;
    cout << "\nmax(3,7) = " << minmax(3, 7).second;
    cout << "\n\nmin({1,3,5,6,10}) = " << min({ 1,3,5,6,10 });

    ostream_iterator<int>output{ cout," " };
    array<int,SIZE> a{ 1,5,7,3,2,4,7,4,4,20 };
    cout << "\n\narray a contains:\n";
    copy(a.cbegin(), a.cend(), output);
    auto minimum = minmax_element(a.cbegin(), a.cend()).first;
    auto maximum = minmax_element(a.cbegin(), a.cend()).second;
    cout << "\nminimum of array a: " << *minimum;
    cout << "\nmaximum of array a: " << *maximum;

    cout << endl;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
