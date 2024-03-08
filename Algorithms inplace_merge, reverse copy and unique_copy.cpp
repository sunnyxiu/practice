// Algorithms inplace_merge, reverse copy and unique_copy.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<array>
#include<vector>
#include<algorithm>
#include<iterator>
#include <iostream>

using std::array;
using std::vector;
using std::ostream_iterator;
using std::inplace_merge;
using std::reverse_copy;
using std::unique_copy;
using std::cout;
using std::endl;
using std::copy;
using std::back_inserter;

int main()
{
    const size_t SIZE{ 10 };
    array<int, SIZE>a1{ 1,2,3,4,5,2,3,5,6,10 };
    ostream_iterator<int>output{ cout," " };

    cout << "a1 contains:\n";
    copy(a1.cbegin(), a1.cend(), output);
    
    cout << "\n\nafter inplace_merge, a1 contains:\n";
    inplace_merge(a1.begin(), a1.begin() + 5, a1.end());
    copy(a1.cbegin(), a1.cend(), output);

    vector<int>result1;
    unique_copy(a1.cbegin(), a1.cend(), back_inserter(result1));
    cout << "\n\nafter unique_copy, result1 contains:\n";
    copy(result1.cbegin(), result1.cend(), output);

    vector<int>result2;
    reverse_copy(a1.cbegin(), a1.cend(), back_inserter(result2));
    cout << "\n\nafter reverse_copy, result2 contains:\n";
    copy(result2.cbegin(), result2.cend(), output);

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
