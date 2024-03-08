#include"Date.h"
#include<iostream>
#include<string>
using std::array;
using std::invalid_argument;
using std::cout;
using std::string;

const array<unsigned int, 13>Date::daysPerMonth{ 
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(unsigned int mm, unsigned int dd, unsigned int yy) {
	setDate(mm, dd, yy);
};

void Date::setDate(unsigned int mm, unsigned int dd, unsigned int yy) {
	if (mm > 0 && mm <= 12) month = mm;
	else {
		throw invalid_argument("Month must be 1-12");
	}
	if (yy >= 1990 && yy <= 2100) year = yy;
	else {
		throw invalid_argument("Year must be 1990-2100");
	}
	if ((month == 2 && dd > 0 && dd <= 29 && leapYear(year))|| 
		(dd > 0 && dd <= daysPerMonth[month])) day = dd;
	else {
		throw invalid_argument("unvalid days");
	}
	
};


Date& Date::operator++(){
	helpIncrement();
	return *this;
};
Date Date::operator++(int){
	Date copyDate{ *this };
	helpIncrement();

	return copyDate;	
};

Date& Date::operator+=(unsigned int addDays){
	for (int i = 1; i <= addDays; i++) {
			helpIncrement();
	}
	return *this;
};

bool Date::leapYear(unsigned int yy) {
	return (yy % 400 == 0 || 
		(yy % 4 == 0 && yy % 100 != 0));
	};
bool Date::lastDayOfMonth(unsigned int dd)const {
	if (month == 2 && leapYear(year)) { 
		return (dd == 29); 
	}
	else {
		return(dd == daysPerMonth[month]);
	}
};

void Date::helpIncrement(){
		if (!lastDayOfMonth(day)) { day++; }
		else{
			if (month < 12) { 
				day=1;
				month++;
			}
			else {
				day = 1;
				month = 1;
				year++;
			}
		}
	};

ostream& operator<<(ostream& output, const Date& date) {
		static string monthName[13]{ "","January","February","March","April","May","June","July","August","September","October","November","December" };
		output << monthName[date.month] << " " << date.day << ", " << date.year;
		return output;
	};