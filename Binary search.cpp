// Binary search.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<algorithm>
#include<ctime>
#include<array>
#include<random>
#include <iostream>

using std::array;
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;

template<typename T, size_t size>
void displayElement(const array<T, size>& items, size_t low, size_t high) {
    for (size_t i{ 0 }; i<items.size() && i < low; i++) {
        cout << "   ";
    }

    for (size_t i{ low }; i<items.size() && i <= high; i++) {
        cout << items[i] << " ";
    }

    cout << endl;
}

template<typename T, size_t size>
int binarySearch(const array<T, size>& items, const T& key) {
    int low{ 0 };
    int high{ static_cast<int>(items.size()) - 1 };
    int middle{ (low + high + 1) / 2 };
    int location{ -1 };

    do{
        displayElement(items, low, high);

        for (size_t i{ 0 }; i < middle; i++) {
            cout << "   ";
        }

        cout << " * "<<endl;

        if (key == items[middle]) {
            location = middle;
        }
        else if (key < items[middle]){
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }

        middle = (low + high + 1) / 2;

    } while ((location == -1) && (low <= high));
    
    return location;
}

int main()
{
    default_random_engine engine{ static_cast<unsigned int>(time(nullptr))};
    uniform_int_distribution<unsigned int>randomInt{ 10,99 };

    const size_t arraySize{ 15 };
    array<int, arraySize> arrayToSearch;
    
    for (int& item : arrayToSearch) {
        item = randomInt(engine);
    }
    
    sort(arrayToSearch.begin(),arrayToSearch.end());

    displayElement(arrayToSearch, 0, arrayToSearch.size() - 1);

    cout << "\nPlease enter an integer value(-1 to quit): ";
    int searchKey;
    cin >> searchKey;
    while (searchKey != -1) {
        int position{ binarySearch(arrayToSearch,searchKey) };
        
        if (position == -1) {
            cout << "The integer " << searchKey << " was not found.\n";
        }
        else {
            cout << "The integer " << searchKey
                << " was found in position " << position << endl;
        }

        cout << "\n\nPlease enter an integer value(-1 to quit): ";
        cin >> searchKey;
        cout << endl;
    }
    

}

