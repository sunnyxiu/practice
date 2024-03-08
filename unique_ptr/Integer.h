#ifndef INTEGER
#define INTEGER

#include<iostream>

using std::cout;
using std::endl;

class Integer {
public:
	Integer(int i = 0) :value{ i } {
		cout << "Constructor for Integer " << value << endl;
	};

	~Integer() {
		cout << "Destructor for Integer " << value << endl;
	};

	void setInteger(int i) {
		value = i;
	}

	int getInteger() const{
		return value;
	}

private:
	int value;
};


#endif // !INTEGER

