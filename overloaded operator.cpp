#include<iostream>
#include<string>
#include<iomanip>

using std::istream;
using std::ostream;
using std::string;
using std::setw;
using std::cout;
using std::endl;
using std::cin;

class PhoneNumber {
	friend istream& operator>>(istream&, PhoneNumber&);
	friend ostream& operator<<(ostream&, PhoneNumber& const);
public:
	
private:
	string areaCode{ 0 };
	string exchange{ 0 };
	string line{ 0 };

};
//(555) 555-5555
istream& operator>>(istream& input ,PhoneNumber& phoneNum) {
	input.ignore();
	input >> setw(3) >> phoneNum.areaCode;
	input.ignore(2);
	input >> setw(3) >> phoneNum.exchange;
	input.ignore();
	input >> setw(4) >> phoneNum.line;
	return input;
};

ostream& operator<<(ostream& output, PhoneNumber& const phoneNum) {
	output << "Area code: " << phoneNum.areaCode << "\nExchange: "
		<< phoneNum.exchange << "\nLine: " << phoneNum.line << "\n"
		<< "(" << phoneNum.areaCode << ")" << phoneNum.exchange << "-"
		<< phoneNum.line << "\n";
	return output;
};

int main() {
	PhoneNumber phone1;
	cout << "Enter phone number in form (xxx) xxx-xxxx" << endl;
	cin >> phone1;
	cout << "\n The phone number entered was: " << endl;
	cout << phone1;



}