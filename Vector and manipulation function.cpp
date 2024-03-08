#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include<iterator>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::copy;
using std::ostream_iterator;
using std::out_of_range;

int main() {
	vector<int>values{ 1,2,3,4,5,6 };
	vector<int>integers{ values.cbegin(),values.cend() };
	ostream_iterator<int> output{ cout," " };

	cout << "Vector integers contains: ";
	copy(integers.cbegin(), integers.cend(), output);

	cout << "\nThe first element of integers: " << integers.front()
		<< "\nThe last element of integers: " << integers.back();
	//Access elements
	integers[0] = 7;
	integers.at(2) = 10;

	integers.insert(integers.cbegin() + 1, 22);

	cout << "\n\nContents of vector integers after changes: ";
	copy(integers.cbegin(), integers.cend(), output);

	try {
		integers.at(100) = 777;
	}
	catch (out_of_range& outOfRange) {
		cout << "\n\nException: " << outOfRange.what();
	}

	integers.erase(integers.cbegin());
	cout << "\n\nVector integers after erasing first element: ";
	copy(integers.cbegin(), integers.cend(), output);

	integers.erase(integers.cbegin(), integers.cend());
	cout << "\nAfter erasing all elements, vector integers "
		<< (integers.empty() ? "is " : "is not ") << "empty";

	integers.insert(integers.cbegin(), values.cbegin(), values.cend());
	cout << "\n\nContents of vector integers before clear: ";
	copy(integers.cbegin(), integers.cend(), output);

	integers.clear();
	cout << "\nAfter clear, vector integers "
		<< (integers.empty() ? "is " : "is not ") << "empty" << endl;

	
}