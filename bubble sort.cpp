// bubble sort.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<array>
#include<random>
#include<ctime>
#include<iomanip>

using std::cout;
using std::endl;
using std::array;
using std::uniform_int_distribution;
using std::default_random_engine;
using std::setw;

template<typename T, size_t size>
void bubbleSort(array<T, size>& items) {
    int swapTimes{ 1 };//better way??
    for (int i{ static_cast<int>(items.size() - 2) }; i >= 0 && swapTimes != 0; i--) {
        swapTimes = 0;
        for (int j{ 0 }; j <= i; j++) {
            if (items[j] > items[j + 1]) {
                T temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
                swapTimes++;
            }
        }
    }
}

int main()
{
    const size_t arraySize{ 8 };
    array<int, arraySize> data;
    default_random_engine engine{ static_cast<unsigned int>(time(nullptr)) };
    uniform_int_distribution<unsigned int> randomInt{ 1,99 };

    for (int i{ 0 }; i < data.size(); i++) {
        data[i] = randomInt(engine);
    }
    
    for (int i{ 0 }; i < data.size(); i++) {
        cout << setw(4) << data[i];
    }

    bubbleSort(data);

    cout << endl;

    for (int i{ 0 }; i < data.size(); i++) {
        cout << setw(4) << data[i];
    }

    cout << endl;

}


