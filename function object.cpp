﻿// function object.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<numeric> //accumulate
#include<algorithm>
#include<array>
#include<iterator>
#include<functional>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::accumulate;
using std::copy;
using std::array;

int squareSum(int total, int value) {
    return total + value * value;
}

template<typename T>
class squareSumObject {
public:
    T operator()(const T& total, const T& value) {
        return total + value * value;
    }
};

int main()
{
    const size_t SIZE{ 10 };
    array<int, SIZE>a{ 1,2,3,4,5,6,7,8,9,10 };
    ostream_iterator<int>output{ cout," " };
    cout << "array a contains:\n";
    copy(a.cbegin(), a.cend(), output);

    int result{ accumulate(a.cbegin(),a.cend(),0,squareSum) };
    cout << "\n\nsquare sum of elements of array a (binary function): " << result;

    result = accumulate(a.cbegin(), a.cend(), 0, squareSumObject<int>{});
    //create an object of squarSumObject and call function operator()
    cout << "\n\nsquare sum of elements of array a (function object): " << result;
    
    result = accumulate(a.cbegin(), a.cend(), 0, [](auto total, auto value) {return total + value * value; });
    cout << "\n\nsquare sum of elements of array a (lambda): " << result;
    
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
