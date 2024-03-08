#pragma once
#include<string>
#include<cmath>
using std::string;
using std::to_string;
using std::abs;
using std::size;

class DollarAmount {
public:
	explicit DollarAmount(int64_t value):amount{value}{};
	void add(DollarAmount value) { amount += value.amount;}
	void substract(DollarAmount value) { amount -= value.amount; }
	string toString()const {
		string dollar{ to_string(amount / 100) };
		string cent{ to_string(abs(amount % 100)) };
		return dollar + "." + (cent.size() == 1 ? "0" : "")+cent;
	}
	void addInterest(int64_t rate, int64_t divisor)
	{
		DollarAmount interest{ (amount * rate+divisor/2) / divisor };
		add(interest);
	}
private:
	int64_t amount{ 0 };
};