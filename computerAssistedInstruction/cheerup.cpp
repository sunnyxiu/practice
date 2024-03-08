#include "computerAssistedInstruction.h"
#include<iostream>

using std::cout;

void cheerup(int num) {
	switch (num) {
	case 0:cout << "No. Please try again."; break;
	case 1:cout << "Wrong. Try once more."; break;
	case 2:cout << "Don't give up!"; break;
	default:cout << "No. Keep trying.";
	}
}
