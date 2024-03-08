#include<iostream>
#include<iomanip>

int main() {
	const int number{20 };
	char b[number];
	const char* bPtr{ b };
	std::cin.getline(b, number, '\n');
	
	std::cout << b;



}