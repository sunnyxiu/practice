#include "computerAssistedInstruction.h"
#include<iostream>

using std::cout;

void compliment(int num) {
	switch (num) {
	case 0:cout << "Very good!"; break;
	case 1:cout << "Excellent!"; break;
	case 2:cout << "Nice work!"; break;
	default:cout << "Keep up the good work!";
	}
}