// remove.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>

using std::array;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::remove;
using std::remove_if;
using std::remove_copy;
using std::remove_copy_if;
using std::copy;

int main()
{
    const size_t SIZE{ 10 };
    array<int, SIZE> unit{ 1,11,2,10,3,9,4,10,5,10 };
    array<int, SIZE> a1(unit);
    ostream_iterator<int> output{ cout," " };
    
    cout << "a1 before remove 10:\n";
    copy(a1.cbegin(), a1.cend(), output);
    
    auto newEnd = remove(a1.begin(), a1.end(), 10);
    cout << "\na1 after removing all 10s:\n";
    copy(a1.begin(),newEnd, output);

    array<int, SIZE>a2(unit);
    array<int, SIZE>c1{ 0 };
    cout << "\n\na2 before remove 10s and copy to c1:\n";
    copy(a2.cbegin(), a2.cend(), output);

    cout << "\n a2 after remove 10s and copy to c1:\n";
    remove_copy(a2.begin(), a2.end(), c1.begin(), 10);
    copy(c1.begin(), c1.end(), output);
    
    array<int, SIZE>a3(unit);
    cout << "\n\na3 before remove elements greater than 9:\n";
    copy(a3.cbegin(), a3.cend(), output);
    newEnd = remove_if(a3.begin(), a3.end(),
        [](auto i) {return (i > 9); });
    cout << "\na3 after remove elements greater than 9:\n";
    copy(a3.begin(), newEnd, output);
    
    array<int, SIZE>a4(unit);
    array<int, SIZE>c2{ 0 };
    cout << "\n\na4 before remove elements greater than 9 and copy to c2:\n";
    copy(a4.cbegin(), a4.cend(), output);
    cout << "\na4 after remove elements greater than 9 and copy to c2:\n";
    newEnd=remove_copy_if(a4.begin(), a4.end(), c2.begin(),
        [](auto i) {return (i > 9); });
    copy(c2.begin(), newEnd, output);

    


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
