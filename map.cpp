
#include<map>
#include <iostream>

using std::map;
using std::cout;
using std::endl;
using std::less;
using std::make_pair;

int main()
{
    map<int,double,less<int>> pairs;

    pairs.insert(make_pair(15, 2.7));
    pairs.insert(make_pair(30, 111.11));
    pairs.insert(make_pair(5, 1010.1));
    pairs.insert(make_pair(10, 22.22));
    pairs.insert(make_pair(25, 33.33));
    pairs.insert(make_pair(5, 77.54));//dup ignored
    pairs.insert(make_pair(20, 9.345));
    pairs.insert(make_pair(15, 99.3));

    cout << "pairs contains:\nKey\tValue\n";
    for (auto mapItem: pairs) {
        cout << mapItem.first << "\t" << mapItem.second << "\n";
    }
    
    pairs[25] = 9999.99;
    pairs[40] = 8765.43;

    cout << "\nAfter subscript operations, pairs contains:\nKey\tValue\n";
    for (auto mapItem : pairs) {
        cout << mapItem.first << "\t" << mapItem.second << "\n";
    }
}


