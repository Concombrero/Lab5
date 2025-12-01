/**
 * @file client.cpp
 * @brief Implementation of the Client class.
 */

#include "client.hpp"
#include "account.hpp"

Client::Client(string name, unsigned int identifier, size_t maxAccounts) {
        this->name = name;
        this->identifier = identifier;
        this->maxAccounts = maxAccounts;
        nb_currentAccounts = 0;

        accounts = new Bank_account*[maxAccounts];
    }

Client::Client(const Client& client) {
    name = client.name;
    identifier = client.identifier;
    maxAccounts = client.maxAccounts;
    nb_currentAccounts = client.nb_currentAccounts;

    accounts = new Bank_account*[client.maxAccounts];
    for (size_t i = 0; i < client.nb_currentAccounts; i++) {
        accounts[i] = client.accounts[i];
    }
}

Client::~Client() {
    for (size_t i = 0; i < nb_currentAccounts; i++) {
        delete accounts[i];
    }
    delete [] accounts;
}

void Client::credit(unsigned int idx, double amount) {
    if(idx >= nb_currentAccounts){
        cout << "Invalid account index." << endl;
    }
    accounts[idx]->credit(amount);
}

double Client::debit(unsigned int idx, double amount) {
    if(idx >= nb_currentAccounts){
        cout << "Invalid account index." << endl;
    }
    return accounts[idx]->debit(amount);
}

bool Client::createAccount(){
    if(nb_currentAccounts >= maxAccounts){
        std::cout << "Maximum number of accounts reached." << std::endl;
        return false;
    }
    std::cout << "Creation of a current account (1), unblocked savings account (2), or blocked savings account (3)?" << endl;
    int choice;
    std::cin >> choice;

    switch(choice){
        case 1:
            accounts[nb_currentAccounts] = new Current_account(nb_currentAccounts, 0);
            nb_currentAccounts++;
            break;
        case 2:
            accounts[nb_currentAccounts] = new Unblocked_account(nb_currentAccounts, 0);
            nb_currentAccounts++;
            break;
        case 3:
            accounts[nb_currentAccounts] = new Blocked_account(nb_currentAccounts, 0);
            nb_currentAccounts++;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return false;
    }
    return true;
}

unsigned int Client::get_id() {
    return identifier;
}


ostream& operator<<(ostream &o, const Client& client) {
    o << "Client name: " << client.name << " and id = " << client.identifier << " and his / her accounts :" << endl;
    
    for (size_t i = 0; i < client.nb_currentAccounts; i++) {
        o << *(client.accounts[i]) << endl;
    }
    return o;
}
