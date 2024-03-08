#include<iostream>
#include<array>
#include<iomanip>

using std::cout;
using std::array;
using std::setw;
using std::endl;

int main() {
	const size_t responseSize{ 20 };
	array<unsigned int, responseSize>response = { 1,2,5,4,3,5,2,1,3,1,4,3,3,3,2,3,3,2,2,5 };
	const size_t frequencySize{ 6 };
	array<unsigned int, frequencySize>frequency={};
	for (unsigned int i{ 0 }; i < response.size(); i++)
		frequency[response[i]]++;
	cout << "Rating" << setw(12) << "Frequency" << endl;
	for (unsigned int j{ 1 }; j < frequency.size(); j++)
		cout << setw(6) << j << setw(12) << frequency[j] << endl;
}