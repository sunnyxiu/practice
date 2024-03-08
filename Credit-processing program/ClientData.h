#ifndef CLIENTDATA_H
#define	CLIENTDATA_H

#include<string>
using std::string;

class ClientData {
public:
		ClientData(int = 0, const string & = "", const string & = "", double = 0.0);

	void setAccountNumber(int);
	int getAccountNumber()const;

	void setLastName(const string&);
	const string& getLastName()const;

	void setFirstName(const string&);
	const string& getFirstName()const;

	void setBalance(double);
	double getBalance()const;

private:
	int accountNumber;
	char lastName[15];
	char firstName[10];
	double balance;
};

#endif // !1

