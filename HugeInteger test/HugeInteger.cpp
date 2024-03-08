#include"HugeInteger.h"

//conversion/default constructor
HugeInteger::HugeInteger(long value) {
	for (int j{ digits - 1 }; j>=0&&value>0; j--) {
		integer[j] = value % 10;
		value /= 10;
	}
};

//conversion constructor
HugeInteger::HugeInteger(const string& number){
	int length= number.size();//size_t

	for (int j{ digits - length },k{0}; j < digits; j++,k++) {
		if (isdigit(number[k])) {//ensure that character is a digit
			integer[j] = number[k] - '0';
		}
	}
};

//addition operator: HugeInteger + HugeInteger
HugeInteger HugeInteger::operator+(const HugeInteger& op2) const {
	HugeInteger temp;
	int carry{0};
	for (int j{ digits - 1 }; j >= 0; j--) {
		temp.integer[j] = integer[j] + op2.integer[j] + carry;

		if (temp.integer[j] >= 10) {
			carry = 1;
			temp.integer[j] %= 10;
		}
		else {
			carry = 0;
		}
	}
	return temp;
};

//addition operator: HugeInteger + int
HugeInteger HugeInteger::operator+(int op2) const {
	return HugeInteger(op2) + *this;
};

//addition operator:
//HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator+(const string& op2) const {
	return HugeInteger(op2) + *this;
};

ostream& operator<<(ostream& output, const HugeInteger& integerToOutput) {
	int i{ 0 };
	//skip leading zeros
	for (i; i < HugeInteger::digits; i++) {
		if (integerToOutput.integer[i] != 0)
			break;
	}
	//all 0
	if (i == HugeInteger::digits) {
		output << 0;
	}
	else {
		for (i; i < HugeInteger::digits; i++) {
			output << integerToOutput.integer[i];
		}
	}
	return output;
};


HugeInteger HugeInteger::operator*(const HugeInteger& op2) const{
	HugeInteger tempTotal;
	int carry{ 0 };
	for (int j{ digits - 1 }; j>=0; j--) {
		HugeInteger temp;
		for (int k{ digits - 1 },l{j}; k >= 0&&l>=0; k--,l--) {
			temp.integer[l] = op2.integer[j] * integer[k] + carry;
			if (temp.integer[l] >= 10) {
				carry = (temp.integer[l]) / 10;
			}
			else {
				carry = 0;
			}
			temp.integer[l] %= 10;
		}
		tempTotal = tempTotal + temp;
	}
	return tempTotal;
};

HugeInteger HugeInteger::operator*(const string& op2) const {
	return (*this) * HugeInteger(op2);
};

HugeInteger HugeInteger::operator*(int op2) const {
	return (*this) * HugeInteger(op2);
};