// mathematical algorithm.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<random>
#include <iostream>
#include<array>
#include<iterator>
#include<numeric>

using std::default_random_engine;
using std::random_device;
using std::shuffle;
using std::array;
using std::ostream_iterator;
using std::cout;
using std::endl;
using std::copy;
using std::count;
using std::count_if;
using std::min_element;
using std::max_element;
using std::minmax_element;
using std::accumulate;
using std::transform;

int main()
{
    const size_t SIZE{ 10 };
    array<int, SIZE>a1{ 1,2,4,5,6,9,3,11,7,0 };
    ostream_iterator<int> output{ cout," " };
    random_device rd{};
    default_random_engine randomEngine{ rd() };
    cout << "a1 before shuffle:\n";
    copy(a1.cbegin(), a1.cend(), output);
    shuffle(a1.begin(), a1.end(), randomEngine);
    cout << "\na1 after shuffle:\n";
    copy(a1.cbegin(), a1.cend(), output);

    array<int, SIZE>a2{ 1,3,5,8,6,3,8,8,10,7 };
    cout << "\n\na2 contains:\n";
    copy(a2.cbegin(), a2.cend(), output);

    auto result = count(a2.cbegin(), a2.cend(), 8);
    cout << "\nNumber of elements matching 8: " << result;

    result = count_if(a2.cbegin(), a2.cend(),
        [](auto x) {return (x > 9); });
    cout << "\nNumber of elements larger than 9: " << result;

    if (!a2.empty()) {
        cout << "\nmin element in a2: " << *min_element(a2.cbegin(), a2.cend());
    }
    else {
        cout << "\na2 is empty";
    }

    if (!a2.empty()) {
        cout << "\nmax elements in a2: " << *max_element(a2.cbegin(), a2.cend());
    }
    else {
        cout << "\na2 is empty";
    }
    if (!a2.empty()) {
        cout << "\nmin element in a2: " << *(minmax_element(a2.cbegin(), a2.cend()).first);
        cout << "\nmax element in a2: " << *(minmax_element(a2.cbegin(), a2.cend()).second);
    }
    else {
        cout<<"\na2 is empty";
    }

    cout << "\n\ntotal of elements of a1: " << accumulate(a1.cbegin(), a1.cend(), 0);

    array<int, SIZE>cubes;

    transform(a1.cbegin(), a1.cend(), cubes.begin(),
        [](auto x) {return x * x * x; });
    cout << "\n\ncubes contains:\n";
    copy(cubes.cbegin(), cubes.cend(), output);


}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤214
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
