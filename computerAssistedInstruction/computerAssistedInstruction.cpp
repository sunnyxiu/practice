//function:ask question
//

#include <iostream>
#include<cstdlib>
#include<ctime>
#include"computerAssistedInstruction.h"

using std::rand;
using std::srand;
using std::cout;
using std::cin;
int main()
{	
	unsigned int answer;
	unsigned int right{ 0 };
	unsigned int wrong{ 0 };
	unsigned int counter=right+wrong;
	srand(static_cast<unsigned int>(time(0)));
	
	int num1 = rand() % 9 + 1;
	int num2 = rand() % 9 + 1;
	askQuestion(num1, num2);
	cin >> answer;
	while(answer!=-1){
		while (answer != (num1 * num2)) {
			cheerup(rand() % 4);
			wrong++;
			cin >> answer;
		}
		compliment(rand() % 4);
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;
		askQuestion(num1, num2);
		cin >> answer;
	}
	

}

