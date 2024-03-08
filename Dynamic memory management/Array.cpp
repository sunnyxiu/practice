#include"Array.h"
#include<stdexcept>

using std::invalid_argument;
using std::out_of_range;
//overloaded operator>>
istream& operator>>(istream& input, Array& arrayToInput) {
	for (size_t i{ 0 }; i < arrayToInput.size;i++) {
		input >> arrayToInput.ptr[i];
	}
	return input;//enables cin >> x >> y;
};
//overloaded operator<<
ostream& operator<<(ostream& output, const Array& arrayToOutput){
	for (size_t i{ 0 }; i < arrayToOutput.size; i++) {
		output << arrayToOutput.ptr[i]<<" ";
	}

	output << std::endl;
	return output;//enables cout << x << y;
};


Array::Array(int arraySize):
	size{(arraySize>0 ? static_cast<size_t>(arraySize):
		throw invalid_argument("Array size must be greater than 0")) }, 
	ptr{ new int[size] {} }{/*empty body*/};


//copy constructor for class Array;
Array::Array(const Array& arrayToCopy) :size{ arrayToCopy.size }, ptr{ new int[size] }{
	for (size_t i = 0; i < size; i++) {
		ptr[i] = arrayToCopy.ptr[i];
	}
};
//destructor
Array::~Array() { 
	delete[] ptr;
};
//return numbers of elements of array
int Array::getSize() const { 
	return size; 
};
//assignment
//const return avoid (a1 = a2) = a3
const Array& Array::operator=(const Array& right) {
	if (&right != this) {//avoid self-assignment
		delete[] ptr;
		if (size != right.size) {
			size = right.size;
			ptr = new int[size];
		}
		
		for (size_t i = 0; i < size; i++) {
			ptr[i] = right.ptr[i];
		}
		return *this;
	}
};
bool Array::operator==(const Array& right)const {
	if (size != right.size) {
		return false;
	}
	for (size_t i{ 0 }; i < size; i++) {
		if (ptr[i] != right.ptr[i]) {
			return false;
		}
	}
	return true;
};//equality operator

bool Array::operator!=(const Array& right)const {
	return !(*this == right);

};//inequality operator; return opposite of == operator

//subscript operator for non-const objects returns modifiable lvalue
int& Array::operator[](int subscript) {
	//check for out-of-range error
	if ((subscript < 0) || (subscript >= size)) {
		throw out_of_range("Subscript out of range");
	}
	return ptr[subscript];
};
//subscript operator for const objects return rvalue
int Array::operator[](int subscript)const {
	if ((subscript < 0) || (subscript >= size) ){
			throw out_of_range("Subscript out of range");
	}
	return ptr[subscript];
};