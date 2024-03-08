#include<iostream>
#include<iomanip>
#include<ctime>
#include<random>

using std::cout;
using std::endl;
using std::default_random_engine;
using std::time;
using std::setw;
using std::uniform_int_distribution;
unsigned int sum() {
	static unsigned int count{ 1 };
	count++;
	return count;
}
int main() {
	cout << sum();
	cout << sum();
}
