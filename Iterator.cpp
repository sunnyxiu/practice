#include<iostream>
#include<iterator>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cbegin;
using std::cend;

template<typename T>
void printVector(const vector<T>&);

int main() {
	vector<int> integers;

	cout << "The initial size of integers is: " << integers.size()
		<< "\nThe initial capacity of integers is: " << integers.capacity();

	integers.push_back(2);
	integers.push_back(3);
	integers.push_back(4);
	integers.push_back(5);

	cout << "\nThe size of integers is: " << integers.size()
		<< "\nThe initial capacity of integers is: " << integers.capacity();
	cout << "\n\nOutput built-in array using pointer notation: ";
	const size_t SIZE{ 6 };
	int values[SIZE]{ 1,2,3,4,5,6 };

	for (const int* ptr = cbegin(values); ptr != cend(values); ptr++) {
		cout << *ptr << ' ';
	}

	cout << "\nOutput vector using iterator notation: ";
	printVector(integers);
	cout << "\nReversed contents of vector integrs: ";

	for (auto reverseIterator = integers.crbegin(); reverseIterator != integers.crend(); ++reverseIterator) {
		cout << *reverseIterator << ' ';
	}

	cout << endl;

}

template<typename T>
void printVector(const vector<T>& integers2) {
	
	for (auto const& item : integers2) {
		cout << item << " ";
	}
	/*
	for (auto constIterator = integers2.cbegin();
		constIterator != integers2.cend();
		++constIterator) {
		cout << *constIterator << ' ';
	}
	*/
}
