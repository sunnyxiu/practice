// muitiset.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<set>
#include <iostream>
#include<algorithm>
#include<array>
#include<iterator>
#include<vector>

using std::vector;
using std::multiset;
using std::endl;
using std::cout;
using std::less;
using std::ostream_iterator;
using std::copy;
using std::equal_range;

int main()
{
    multiset<int, less<int>> intMultiset;//less<int> for ascending order
    cout << "There are currently " << intMultiset.count(15)
        <<" values of 15 in the multiset\n";

    intMultiset.insert(15);
    intMultiset.insert(15);
    cout << "After inserts, there are " << intMultiset.count(15)
        << " values of 15 in the multiset\n\n";

    auto result{ intMultiset.find(15) };
    if (result != intMultiset.end()) {
        cout << "Found value 15\n";
    }

    result = intMultiset.find(20);
    if (result == intMultiset.end()) {
        cout << "Did not find value 20\n";
    }

    vector<int>a{ 7,22,9,1,18,30,100,22,85,13 };
    intMultiset.insert(a.cbegin(), a.cend());
    intMultiset.insert(intMultiset.cbegin(), 5);
    cout << "\nAfter insert, intMultiset contains:\n";
    ostream_iterator<int>output{ cout," " };
    copy(intMultiset.cbegin(), intMultiset.cend(), output);

    auto bound{ intMultiset.lower_bound(99) };
    if (bound != intMultiset.end()) {
        cout << "\n\nLower bound of 99: " << *bound;
    }
    else {
        cout << "Did not find value ";
    }

    bound = intMultiset.upper_bound(99);
    if (bound != intMultiset.end()) {
        cout << "\nUpper bound of 99: " << *bound;
    }
    else {
        cout << "Did not find value ";
    }

    auto p{ intMultiset.equal_range(22) };
    cout << "\n\nequal_range of 22:"
        << "\n   Lower bound: " << *(p.first)
        << "\n   Upper bound: " << *(p.second);
    cout << endl;


}

