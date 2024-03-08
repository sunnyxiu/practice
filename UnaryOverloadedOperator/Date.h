#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<array>

using std::ostream;
using std::array;


class Date {
	friend  ostream& operator<<(ostream&, const Date&);
public:
	Date(unsigned int=1, unsigned int=1, unsigned int=1990);
	void setDate(unsigned int, unsigned int, unsigned int);
	Date& operator++();
	Date operator++(int);
	Date& operator+=(unsigned int);

	static bool leapYear(unsigned int);
	bool lastDayOfMonth(unsigned int) const;

private:
	unsigned int month;
	unsigned int day;
	unsigned int year;


	static const array<unsigned int, 13>daysPerMonth;
	void helpIncrement();
};



#endif
