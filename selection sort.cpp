// selection sort.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<array>
#include<iomanip>

using std::array;
using std::cout;
using std::endl;
using std::setw;

template<typename T>
void swap(T& a, T& b) {
    T temp{ a };
    a = b;
    b = temp;
}
template<typename T, size_t size>
void selection_sort(array<T, size>& array1) {
    for (int i{ 0 }; i < array1.size()-1; i++) {
        int smallest=i;
        for (int j{ i + 1 };j< array1.size(); j++) {
            if (array1[j] < array1[smallest]) {
                smallest = j;
            }
        }
        if (smallest != i) {
            T temp{ array1[i] };
            array1[i] = array1[smallest];
            array1[smallest] = temp;
        }
        
    }
}
int main()
{
    const size_t arraySize{ 10 };
    array<int, arraySize> array1{10, 9, 8, 7, 6, 5, 4, 3, 3, 1};

    cout << "Unsorted array:\n";

    for (int i{ 0 }; (i < array1.size()); i++) {
        cout << setw(4)<<array1[i];
    }
    cout << endl;

    selection_sort(array1);

    cout << "\nSorted array:\n";
    for (int i{ 0 }; i < array1.size(); i++) {
        cout << setw(4) << array1[i];
    }
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
