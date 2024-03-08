
#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::string;

void outputLine(int, const string&, double);

int main()
{
	ifstream inClientFile;
	inClientFile.open("clients.txt", std::ios::in);

	if (!inClientFile) {
		std::cerr << "File could not be opened" << endl;
		std::exit(EXIT_FAILURE);
	}

	cout << std::left << std::setw(10) << "Account" << std::setw(13)
		<< "Name" << "Balance\n" << fixed << std::showpoint;

	int account;
	string name;
	double balance;
	
	while (inClientFile >> account >> name >> balance) {
		outputLine(account,name,balance);
	}

}

void outputLine(int account, const string& name, double balance) {
	cout <<  std::setw(10)<<std::left  << account << std::setw(13)
		<< name << std::setprecision(2)<<std::right << std::setw(7) << balance<<endl;
}

