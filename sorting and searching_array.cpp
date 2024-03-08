#include <iostream>
#include<array>
#include<algorithm>
#include<string>
using std::string;
using std::array;
using std::cout;
using std::sort;
using std::endl;
using std::binary_search;

int main()
{
    const size_t arraySize{7};
    array<string, 7>rainbow{ "red","orange","yellow","green","blue","indigo","purple" };

    cout << "Unsorted array:\n";
    for (string rainbowColor : rainbow) cout << rainbowColor << " ";

    sort(rainbow.begin(),rainbow.end());

    cout << "\nSorted array:\n";
    for (string rainbowColor : rainbow) cout << rainbowColor << " ";

    bool found{ binary_search(rainbow.begin(),rainbow.end(),"indigo") };
    cout << endl;
    cout << "\n\"indigo\"" << (found ? " was" : " was not") << " found in colors" << endl;
    
    found = binary_search(rainbow.begin(), rainbow.end(), "cyan");
    cout << "\n\"cyan\"" << (found ? " was" : " was not") << " found in colors" << endl;
}

