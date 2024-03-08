#include<iostream>
#include<random>
#include<ctime>
#include<iomanip>
#include<array>

using std::cout;
using std::setw;
using std::array;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;

int main() {
	
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> randomInt(1, 6);
	const size_t arraysize{ 7 };
	array<unsigned long, 7>frequency{};
	for (unsigned int counter{ 1 }; counter <= 6'000'000; counter++) {
		frequency[randomInt(engine)]++;
	}
	cout << "Face" << setw(13) << "Frequency" << endl;
	for (unsigned int dot{ 1 }; dot <= 6; dot++) {
		cout << setw(4) << dot << setw(13) << frequency[dot]<<endl;
	}
}


