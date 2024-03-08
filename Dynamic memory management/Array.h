#ifndef ARRAY_H
#define ARRAY_H

#include<iostream> 
#include<initializer_list>

using std::ostream;
using std::istream;
using std::initializer_list;
class Array {
	friend ostream& operator<<(ostream&, const Array&);//overloaded operator<<
	friend istream& operator>>(istream&, Array&);//overloaded operator>>

public:
	Array(int=10);//default constructor
	Array(const Array&);//copy constructor
	~Array();//destructor
	int getSize() const;//return size
	
	const Array& operator=(const Array&);//assignment
	bool operator==(const Array&)const;//equality operator

	bool operator!=(const Array&)const;//inequality operator; return opposite of == operator
	
	//subscript operator for non-const objects returns modifiable lvalue
	int& operator[](int);
	//subscript operator for const objects return rvalue
	int operator[](int)const;
private:
	size_t size;//pointer-based array size
	int* ptr;//pointer to the first element of pointer-based array
};

#endif

