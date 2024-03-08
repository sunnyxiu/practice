#include<stdexcept>
#include<sstream>
#include<iomanip>
#include<string>
#include<iostream>
#include"Time.h"

using std::invalid_argument;
using std::ostringstream;
using std::setfill;
using std::setw;
using std::cout;

Time::Time():Time{0,0,0}{};
Time::Time(int hr):Time{hr,0,0}{};
Time::Time(int hr, int min):Time{hr,min,0}{};
Time::Time(int hr, int min, int sec) { setTime(hr, min, sec); };

void Time::setTime(int hr, int min, int sec) {
	setHour(hr);
	setMinute(min);
	setSecond(sec);
};
void Time::setHour(int hr) {
	if(hr>=0&&hr<24)
	{ hour = hr; }
	else {
		throw invalid_argument("Hour must be 0-23");
	}
};
void Time::setMinute(int min) {
	if (min >= 0 && min < 60) {
		minute = min;
	}
	else {
		throw invalid_argument("Minute must be 0-59");
	}
};
void Time::setSecond(int sec) {
	if (sec >= 0 && sec < 60) {
		second = sec;
	}
	else {
		throw invalid_argument("Second must be 0-59");
	}
}
unsigned int&  Time::setHourRef(int hr) {
	if (hr >= 0 && hr < 24)
	{
		hour = hr;
		return hour;
	}
	else {
		throw invalid_argument("Hour must be 0-23");
	}
};

unsigned int Time::getHour()const { return hour; } ;
unsigned int Time::getMinute() const { return minute; };
unsigned int Time::getSecond() const { return second; };

string Time::toStandardString()const {
	ostringstream output;
	output << setfill('0') << setw(2) << (getHour() == 0 || getHour() == 12 ? 12 : getHour() % 12) << ":" << setw(2) << getMinute() << ":" << setw(2) <<getSecond() << (getHour() >= 12 ? " PM" : " AM");
	return output.str();
};
string Time::toUniversalString()const {
	ostringstream output;
	output << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << second;
	return output.str();
};
