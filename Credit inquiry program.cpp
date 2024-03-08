#include<fstream>
#include <iostream>
#include<iomanip>
#include<string>
#include<cstdlib>

using std::string;

enum class RequestType {
    ZERO_BALANCE = 1, CREDIT_BALANCE,DEBIT_BALANCE,END
};

RequestType getRequest();
bool shouldDisplay(RequestType, double);
void outputLine(int, const string&, double);

int main()
{
    /*
    std::ofstream outClientFile("clients.txt",std::ios::out);

    if (!outClientFile) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter the account, name, and balance.\n"
        << "Enter end-of-file to end input.\n? ";

    int account;
    string name;
    double balance;

    while (std::cin >> account >> name >> balance) {
        outClientFile << account << ' ' << name << ' ' << balance << std::endl;
        std::cout << "? ";
    }
    */
    std::ifstream inClientFile{"clients.txt",std::ios::in};

    if (!inClientFile) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    RequestType request{ getRequest() };
    
    while (request != RequestType::END) {
        switch(request){
        case RequestType::ZERO_BALANCE:
            std::cout << "\nAccounts with zero balances:\n";
            break;
        case RequestType::CREDIT_BALANCE:
            std::cout << "\n Accounts with credit balances:\n";
            break;
        case RequestType::DEBIT_BALANCE:
            std::cout << "\n Accounts with debit balances:\n";
            break;
        }

        int account;
        string name;
        double balance;

        inClientFile >> account >> quoted(name) >> balance;

        while (!inClientFile.eof()) {
            if (shouldDisplay(request, balance)) {
                outputLine(account, name, balance);
            }

            inClientFile >> account >> name >> balance;
        }

        inClientFile.clear();
        inClientFile.seekg(0);
        request = getRequest();
    }

    std::cout << "End of run."<<std::endl;
    
}

RequestType getRequest() {
    std::cout << "\nEnter request\n"
        << " 1 - List accounts with zero balances\n"
        << " 2 - List accounts with credit balances\n"
        << " 3 - List accounts with debit balances\n"
        << " 4 - End of run" << std::fixed << std::showpoint;
    int type;

    do {
        std::cout << "\n? ";
        std::cin >> type;
    } while (type<static_cast<int>(RequestType::ZERO_BALANCE) ||
        type>static_cast<int>(RequestType::END));
    return static_cast<RequestType>(type);
}

bool shouldDisplay(RequestType type, double balance) {
    if (type == RequestType::ZERO_BALANCE && balance == 0) {
        return true;
    }

    if (type == RequestType::CREDIT_BALANCE && balance < 0) {
        return true;
    }
    if (type == RequestType::DEBIT_BALANCE && balance > 0) {
        return true;
    }

    return false;
}

void outputLine(int account, const string& name, double balance) {
    std::cout << std::left << std::setw(10) << account << std::setw(13) << name
        << std::setw(7) << std::setprecision(2) << std::right << balance << std::endl;
}
