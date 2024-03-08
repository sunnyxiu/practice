#include"ClientData.h"
#include<string>

ClientData::ClientData(int accountNumberValue, const string& lastName,
	const string& firstName, double balanceValue) 
	:accountNumber{ accountNumberValue }, balance{ balanceValue } { 
	setLastName(lastName);
	setFirstName(firstName);
};

void ClientData::setAccountNumber(int accountNumberValue) { 
	
	accountNumber = accountNumberValue; 
};
int ClientData::getAccountNumber()const { return accountNumber; };

void ClientData::setLastName(const string& lastNameValue){
	size_t length{ lastNameValue.size() };
	length = (length < 15 ? length : 14);
	lastNameValue.copy(lastName, length);
	lastName[length] = '\0';
};
const string& ClientData::getLastName()const { return lastName; };

void ClientData::setFirstName(const string& firstNameValue){
	size_t length{ firstNameValue.size() };
	length = (length < 10 ? length : 9);
	firstNameValue.copy(firstName, length);
	firstName[length] = '\0';
};
const string& ClientData::getFirstName()const { return firstName; };

void ClientData::setBalance(double balanceValue) { balance = balanceValue; };
double ClientData::getBalance()const { return balance; };