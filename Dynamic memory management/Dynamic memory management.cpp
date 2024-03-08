#include <iostream>
#include"Array.h"

using std::cout;

void outputArray(const Array&);

int main()
{
	Array integer1{ 7 };
	outputArray(integer1);
	outputArray(Array{3});
	outputArray(5);
	/*
	Array integer1{ 7 };
	Array integer2;

	cout << "Size of array integer1 is: " << integer1.getSize()
		<<"\nArray after initialization: "<<integer1;

	cout << "Size of array integer1 is: " << integer2.getSize()
		<< "\nArray after initialization: " << integer2;
	Array integerByList{ 1,2,3,4,5 };
	cout << "Size of array integerByList is: " << integerByList.getSize()
		<< "\nArray after initialization: " << integerByList;
	
	cout << "\nEnter 17 integers:" << std::endl;
	std::cin >> integer1 >> integer2;

	cout << "\nAfter input, the Arrays contain:\n"
		<< "integer1: " << integer1
		<< "integer2: " << integer2;

	cout << "\nEvaluating: integer1 != integer2" << std::endl;
	if (integer1 != integer2)
		cout << "integer1 and integer2 are not equal" << std::endl;

	Array integer3{ integer1 };

	cout << "\nSize of Array integers3 is " << integer3.getSize()
		<< "\nArray after initialization: " << integer3;

	cout << "\nAssigning integer2 to integer1: " << std::endl;
	integer1 = integer2;

	cout << "integer1: " << integer1 << "integer2: " << integer2;

	cout << "\nEvaluating: integer1 == integer2" << std::endl;
	if (integer1 == integer2)
		cout << "integer1 and integer2 are equal" << std::endl;

	cout << "\ninteger1[5] is " << integer1[5];

	cout << "\n\nAssigning 1000 to integer1[5]" << std::endl;
	integer1[5]=1000;
	cout << "integer1: " << integer1;

	try {
		integer1[15] = 1000;
	}
	catch (std::out_of_range& ex) {
		cout << "An exception occurred: "<<ex.what() << std::endl;
	}

	*/

}

void outputArray(const Array& arrayToOutput) {
	cout << "The array has " << arrayToOutput.getSize()
		<< " elements. The contents are:\n" << arrayToOutput << std::endl;
};