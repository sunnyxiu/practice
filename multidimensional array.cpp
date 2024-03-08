#include <iostream>
#include<array>

using std::cout;
using std::array;

const size_t column{ 3 };
const size_t row{ 2 };
void printArrayByForRange(array< array <size_t, column>, row>const& a);
void printArrayByForCounter(array< array <size_t, column>, row>const& a);

int main()
{
    //define 2x3 array1 and array2

    array<array<size_t, column>, row> array1 = { 1,2,3,4,5,6 };
    array<array<size_t, column>, row> array2 = { 1,2,3,4,5 };

    cout << "Values in array1 by row are:\n";
    printArrayByForCounter(array1);
    //printArrayByForRange(array1);
    cout << "\nValues in array2 by row are:\n";
    printArrayByForCounter(array2);
    //printArrayByForRange(array2);
    
}

void printArrayByForRange(const array< array <size_t, column>, row>& a) {
    size_t total{ 0 };
    for (auto const& rows : a) {
        for (auto const& elements : rows) {
            cout << elements << " ";
            total += elements;
        }
        cout << std::endl;
    }

    cout << "Total of array values is: " << total<<std::endl;

};
void printArrayByForCounter(array< array <size_t, column>, row>const& a) {
    size_t total{ 0 };
    for (size_t row{ 0 }; row < a.size(); row++) {
        for (size_t element{ 0 }; element < a[row].size(); element++) {
            cout << a[row][element] << " ";
            total += a[row][element];
        }
        cout << std::endl;
    }

    cout << "Total of array values is: " << total<<std::endl;
};
