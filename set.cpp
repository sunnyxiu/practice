// set.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<array>
#include<set>
#include <iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using std::vector;
using std::copy;
using std::ostream_iterator;
using std::set;
using std::array;
using std::cout;
using std::endl;
using std::less;
int main()
{
    vector<double> a{ 2.1,4.2,9.5,2.1,3.7 };
    set<double, less<double>> doubleSet{a.cbegin(), a.cend()};

    cout << "doubleSet contains: ";
    ostream_iterator<double>output{ cout," " };
    copy(doubleSet.begin(), doubleSet.end(),output);

    auto p{ doubleSet.insert(13.8) };
    cout << "\n\n" << *(p.first)  
        << (p.second ? " was" : " was not") << " inserted";
    cout << "\ndoubleSet contains: ";
    copy(doubleSet.begin(), doubleSet.end(), output);

    p = doubleSet.insert(9.5);
    cout << "\n\n" << *(p.first)
        << (p.second ? " was" : " was not") << " inserted";
    cout << "\ndoubleSet contains: ";
    copy(doubleSet.begin(), doubleSet.end(), output);
    cout << endl;
}
 
