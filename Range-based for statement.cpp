
#include <iostream>
#include<array>
using std::cout;
using std::array;

int main()
{
    array<int, 5>arrayname={1,2,3,4,5};
    for (int item : arrayname) {
        cout << item << " ";
    }

    for (int& itemRef : arrayname) {
        itemRef *= 2;
    }

    for (int item : arrayname) {
        cout << item << " ";
    }
}

