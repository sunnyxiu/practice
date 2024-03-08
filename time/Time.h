#include <string>
using std::string;

#ifndef TIME_H
#define TIME_H


class Time {
public:
	Time();
	explicit Time(int);
	Time(int,int);
	Time(int, int,int);

	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	unsigned int& setHourRef(int);

	unsigned int getHour() const;
	unsigned int getMinute() const;
	unsigned int getSecond() const;

	string toStandardString() const;
	string toUniversalString() const;

private:
	unsigned int hour{ 0 };
	unsigned int minute{ 0 };
	unsigned int second{ 0 };
};

#endif