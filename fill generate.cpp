// fill generate.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<algorithm>
#include<array>
#include<iterator>

using std::cout;
using std::endl;
using std::copy;
using std::ostream_iterator;
using std::array;
using std::fill;
using std::fill_n;
using std::generate;
using std::generate_n;

char nextLetter() {
    static char letter{ 'A' };
    return letter++;
}

int main()
{
    array<char, 10>chars;
    ostream_iterator<char>output{ cout," " };
    fill(chars.begin(), chars.end(), '5');

    cout << "chars after filling with 5s:\n";
    copy(chars.begin(), chars.end(), output);

    fill_n(chars.begin(), 5, 'A');

    cout << "\n\nchars after filling five elements with As:\n";
    copy(chars.begin(), chars.end(), output);

    generate(chars.begin(), chars.end(), nextLetter);
    
    cout << "\n\nchars after generating letters A-J:\n";
    copy(chars.begin(), chars.end(), output);
    
    generate_n(chars.begin(), 5, nextLetter);

    cout << "\n\nchars after generating K-0 for the first five elements:\n";
    copy(chars.begin(), chars.end(), output);
    cout << endl;

    generate_n(chars.begin(), 3,
        []() {
            static char letter{ 'A' }; 
            return letter++; 
        }
    );

    cout << "\n\nchars after generating A-C for the first three elements:\n";
    copy(chars.begin(), chars.end(), output);
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
