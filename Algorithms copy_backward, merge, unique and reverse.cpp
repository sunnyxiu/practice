// Algorithms copy_backward, merge, unique and reverse.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<algorithm>
#include<iterator>
#include <iostream>
#include<array>
#include<vector>

using std::ostream_iterator;
using std::copy;
using std::copy_backward;
using std::array;
using std::vector;
using std::merge;
using std::unique;
using std::reverse;
using std::cout;
using std::endl;
using std::copy_if;
using std::copy_n;

int main()
{
    const size_t SIZE{ 5 };
    array<int, SIZE>a1{ 2,3,5,7,8 };
    array<int, SIZE>a2{ 1,6,7,8,10 };
    array<int, SIZE>result;
    ostream_iterator<int>output{ cout," " };

    cout << "a1 contains:\n";
    copy(a1.cbegin(), a1.cend(), output);
    cout << "\n\na2 contains:\n";
    copy(a2.cbegin(), a2.cend(), output);
    
    copy_backward(a1.cbegin(), a1.cend(), result.end());
    cout << "\n\nafter copy_backward, result contains:\n";
    copy(result.cbegin(), result.cend(), output);

    array<int, SIZE + SIZE>result2;
    merge(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend(), result2.begin());
    cout << "\n\nafter merge, result2 contains:\n";
    copy(result2.cbegin(), result2.cend(), output);

    auto endLocation{ unique(result2.begin(),result2.end()) };
    cout << "\n\nafter unique, result2 contains:\n";
    copy(result2.begin(), endLocation, output);

    vector<int> result3;
    merge(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend(), back_inserter(result3));
    cout << "\n\nafter merge, result3 contains:\n";
    copy(result3.cbegin(), result3.cend(), output);
    
    cout << "\n\nafter reverse, a1 contains:\n";
    reverse(a1.begin(), a1.end());
    copy(a1.cbegin(), a1.cend(), output);

    array<int, SIZE>result4;
    auto location{ copy_if(a1.cbegin(), a1.cend(), result4.begin(), [](auto x) {return (x > 3); }) };
    cout << "\n\nafter copy elements greater than 3 from a1, result4 contains:\n";
    copy(result4.begin(), location, output);

    array<int, SIZE>result5;
    copy_n(a1.cbegin(), 5, result5.begin());
    cout << "\n\nafter copy 5 elements from a1, result5 contains:\n";
    copy(result5.cbegin(), result5.cend(), output);
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
