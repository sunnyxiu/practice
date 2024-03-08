// merge sort.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<random>
#include<ctime>
#include<array>

using std::cout;
using std::endl;
using std::array;
using std::default_random_engine;
using std::uniform_int_distribution;

template<typename T, size_t size>
void displayElement(const array<T, size>& items,size_t low, size_t high) {
    for (size_t i{ 0 }; i < low && i < items.size(); i++) {
        cout << "   ";
    }
    for (size_t i{ low }; i <= high && i < items.size(); i++) {
        cout << items[i] << " ";
    }
    
    cout << endl;
}

template<typename T, size_t size>
void merge(array<T, size>& items,
    size_t left, size_t middle1, size_t middle2, size_t right) {
    size_t leftIndex{ left };
    size_t rightIndex{ middle2 };
    size_t combinedIndex{ left };
    array<T, size> combined;

    cout << "merge:   ";
    displayElement(items, left, middle1);
    cout << "         ";
    displayElement(items, middle2, right);
    cout << endl;

    while (leftIndex <= middle1 && rightIndex <= right) {
        if (items[leftIndex] <= items[rightIndex]) {
            combined[combinedIndex++] = items[leftIndex++];
        }
        else {
            combined[combinedIndex++] = items[rightIndex++];
        }
    }

    if (leftIndex == middle2) {
        while (rightIndex <= right) {
            combined[combinedIndex++] = items[rightIndex++];
        }
    }
    else {
        while (leftIndex <= middle1) {
            combined[combinedIndex++] = items[leftIndex++];
        }
    }

    for (size_t i{ left }; i <= right; i++) {
        items[i] = combined[i];
    }

    cout << "         ";
    displayElement(items, left, right);
    cout << endl;
}

template<typename T, size_t size>
void mergeSort(array<T, size>& items, size_t low, size_t high) {
    if ((high - low) >= 1){
        size_t middle1{ (low + high) / 2 };
        size_t middle2{ middle1 + 1 };
        cout << "split:   ";
        displayElement(items, low, high);
        cout << "         ";
        displayElement(items, low, middle1);
        cout << "         ";
        displayElement(items, middle2, high);

        mergeSort(items, low, middle1);
        mergeSort(items, middle2, high);

        merge(items, low, middle1, middle2, high);
    }
}



int main()
{
    default_random_engine engine{ 
        static_cast<unsigned int>(time(nullptr))};
    uniform_int_distribution<unsigned int> randomInt{ 10,99 };

    const size_t arraySize{ 10 };
    array<int, arraySize> data;

    for (int& items : data) {
        items = randomInt(engine);
    }

    cout << "Unsorted array:" << endl;
    displayElement(data, 0, data.size() - 1);
    cout << endl;
    
    mergeSort(data, 0, data.size() - 1);
    
    cout << "Sorted array:" << endl;
    displayElement(data, 0, data.size() - 1);
}


