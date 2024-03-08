// list.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::vector;
using std::ostream_iterator;
template<typename T> void printList(const list<T>& listRef);
bool comparator(int first, int second) {
    return (first < second);
}

int main()
{
    list<int> values;
    list<int> otherValues;

    values.push_front(1);
    values.push_front(2);
    values.push_back(4);
    values.push_back(3);

    cout << "values contains: ";
    printList(values);

    values.sort();
    cout << "\nvalues after sorting contains: ";
    printList(values);

    vector<int> ints{ 2,6,4,8 };
    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    cout << "\nAfter insert, otherValues contains: ";
    printList(otherValues);

    values.splice(values.cend(), otherValues);
    cout << "\nAfter splice, values contains: ";
    printList(values);
    cout << "\nAfter splice, otherValues contains: ";
    printList(otherValues);

    values.sort();
    cout << "\nAfter sort, values contains: ";
    printList(values);

    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    otherValues.sort();
    cout << "After insert and sort, otherValues contains: ";
    printList(otherValues);

    values.merge(otherValues,comparator);
    cout << "\nAfter merge, values contains: ";
    printList(values);

    values.pop_front();
    cout << "\nAfter pop_front, values contains: ";
    printList(values);
    
    values.unique();
    cout << "\nAfter unique, values contains: ";
    printList(values);
    
    otherValues.push_back(1);

    values.swap(otherValues);
    cout << "\nAfter swap, values contains: ";
    printList(values);
    cout << "\nAfter swap, otherValues contains: ";
    printList(otherValues);

    values.assign(3,4);
    cout << "\nAfter assign, values contains: ";
    printList(values);
}

template<typename T> void printList(const list<T>& listRef) {
    if (listRef.empty()) {
        cout << "List is empty";
    }
    else{
    ostream_iterator<T> output{ cout," " };
    copy(listRef.cbegin(), listRef.cend(), output);
    }
};
