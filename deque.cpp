// deque.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<deque>
#include<algorithm>
#include<iterator>

using std::deque;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;

int main()
{
    deque<double> values;
    ostream_iterator<double> output{ cout," "};
    values.push_front(2.2);
    values.push_front(3.5);
    values.push_back(1.1);

    cout << "values contains: ";

    for (size_t i{ 0 }; i < values.size(); i++) {
        cout << values[i]<<" ";
    }

    values.pop_front();
    cout << "\nAfter pop_front, values contains: ";
    copy(values.cbegin(), values.cend(), output);

    values[1] = 5.4;
    cout << "\nAfter values[1] = 5.4, values contains: ";
    copy(values.cbegin(), values.cend(), output);
    cout << endl;
    values.insert(values.cbegin() + 1, 4.3);
    cout << "\nAfter insert, values contains: ";
    copy(values.cbegin(), values.cend(), output);
    cout << endl;
    
}

