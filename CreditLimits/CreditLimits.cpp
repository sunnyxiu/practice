#include<iostream>
#include<iomanip>
#include"dollarAmount.h"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main() {
	DollarAmount d1{ 12345 };
	DollarAmount d2{ 1576 };
	cout << "After adding d2 (" << d2.toString() << ") " << "into d1 (" << d1.toString() << "), d1 = "; 
	d1.add(d2);
	cout << d1.toString() << endl;
	cout << "After substracting d2 (" << d2.toString() << ") from d1 (" << d1.toString() << "), d1 = ";
	d1.substract(d2);
	cout << d1.toString() << endl;
	cout << "After substracting d1 (" << d1.toString() << ") from d2 (" << d2.toString() << "), d2 = ";
	d2.substract(d1);
	cout << d2.toString() << endl;

	cout << "\nEnter integer interest rate and divisor. For example:" << endl;
	cout << "for     2%, enter:    2 100" << endl;
	cout << "for   2.3%, enter:   23 1000" << endl;
	cout << "for  2.37%, enter:  237 10000" << endl;
	cout << "for 2.375%, enter: 2375 100000" << endl;
	int rate;
	int divisor;
	cin >> rate >> divisor;
	DollarAmount initialBalance(100000);
	cout << "\nInitial balance: " << initialBalance.toString() << endl;
	cout << "Year" << setw(20) << "Amount on deposit" << endl;
	for (unsigned int year{ 1 }; year <= 10; year++) {
		initialBalance.addInterest(rate, divisor);
		cout << setw(4) << year<<setw(20) << initialBalance.toString() << endl;
	}

}