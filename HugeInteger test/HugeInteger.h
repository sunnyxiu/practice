#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
#include<array>
#include<string>
#include<iostream>

using std::array;
using std::string;
using std::ostream;

class HugeInteger {
	friend ostream& operator<<(ostream&, const HugeInteger&);
public:
	static const int digits{ 40 };
	HugeInteger(long = 0);//conversion/default constructor
	HugeInteger(const string&);//conversion constructor

	//addition operator: HugeInteger + HugeInteger
	HugeInteger operator+(const HugeInteger&) const;
	
	//addition operator: HugeInteger + int
	HugeInteger operator+(int) const;

	//addition operator:
	//HugeInteger + string that represents large integer value
	HugeInteger operator+(const string&) const;

	HugeInteger operator*(const HugeInteger&) const;

	HugeInteger operator*(const string&) const;

	HugeInteger operator*(int) const;
private:
	array<short, digits> integer{};






};






#endif
