// Credit-processing program.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<fstream>
#include"ClientData.h"
#include<cstdlib>
#include<iomanip>
using namespace std;

void outputLine(std::ostream&, const ClientData&);

int main()
{
	/*
	std::ofstream outCredit("credit.dat", std::ios::out | std::ios::binary);
	if (!outCredit) {
		std::cerr << "File could not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}

	ClientData blankClient;
	
	for (int i = 1; i <= 100; i++) {
		outCredit.write(
		reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
	}
	
	
	std::fstream outCredit("credit.dat", std::ios::in | std::ios::out | std::ios::binary);
	if (!outCredit) {
		std::cerr << "File could not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Enter account number (1-100, 0 to end input)\n? ";

	int accountNumber;
	string lastName;
	string firstName;
	double balance;

	std::cin >> accountNumber;

	while (accountNumber > 0 && accountNumber <= 100) {
		std::cout << "Enter lastname, firstname and balance.\n? ";
		std::cin >> lastName ;
		std::cin >> firstName ;
		std::cin >> balance;

		ClientData client{ accountNumber,lastName,firstName,balance };

		outCredit.seekp(
			sizeof(ClientData) * (client.getAccountNumber() - 1));
		outCredit.write(
			reinterpret_cast<const char*>(&client), sizeof(ClientData));

		std::cout << "Enter account number\n? ";
		std::cin >> accountNumber;
	}
	*/
	
   std::ifstream inCredit{"credit.dat",std::ios::in|std::ios::binary};

   if (!inCredit) {
	   std::cerr << "File could not be opened" << std::endl;
	   exit(EXIT_FAILURE);
	}

   std::cout << std::setw(10) << std::left << "Account" << std::setw(16) << "Last name"
	   << std::setw(11) << "First name" << std::setw(10) << std::right << "Balance\n";

   ClientData client;
	
   inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
   
   while (inCredit) {
	   if (client.getAccountNumber() != 0) {
		   outputLine(std::cout, client);
	   }

	   inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

   }
   
   
}

void outputLine(std::ostream& output, const ClientData& record) {
	output << std::setw(10) << std::left << record.getAccountNumber()
		<< std::setw(16) << record.getLastName()
		<< std::setw(11) << record.getFirstName()
		<< std::setw(10) << std::setprecision(2) << std::right << std::fixed
		<< std::showpoint << record.getBalance() << std::endl;
};

