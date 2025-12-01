/**
 * @file account.cpp
 * @brief Implementation of the Bank_account and its derived classes.
 */

#include "account.hpp"

// Bank_account
Bank_account::Bank_account(unsigned int bank_id, double balance) {
    this->bank_id = bank_id;
    this->balance = balance;
}

void Bank_account::credit(double amount) {
    balance += amount;
}

unsigned int Bank_account::operator()() const {
    return bank_id;
}

ostream& operator<<(ostream &o, const Bank_account &account) {
    account.print(o);
    return o;
}

// Current_account
Current_account::Current_account(unsigned int bank_id, double balance) : 
    Bank_account(bank_id, balance) {}

double Current_account::debit(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return amount;
    } else if (balance > 0) {
        double res = balance;
        balance = 0;
        return res;
    } else {
        return 0;
    }
}

void Current_account::print(ostream &o) const {
    o << "** Current account **" << endl;
    o << "Account number = " << (*this)() << ", balance = " << balance << " euros";
}
// Saving_account
Saving_account::Saving_account(unsigned int bank_id, double balance, double interest_rate) : Bank_account(bank_id, balance) {
    this->interest_rate = interest_rate; 
}

void Saving_account::print(ostream &o) const {
    o << "** Savings account **" << endl;
    o << "Account number = " << (*this)() << ", balance = " << balance << " euros\nand Interest rate = " << interest_rate << "%";
}

void Saving_account::add_interest(double interest) {
    interest_rate += interest;
}

// Blocked_account
Blocked_account::Blocked_account(unsigned int bank_id, double balance) : 
    Saving_account(bank_id, balance, IRATEBLOCKED) {}

double Blocked_account::debit([[maybe_unused]] double amount) {
    return -1;
}

// Unblocked account
Unblocked_account::Unblocked_account(unsigned int bank_id, double balance) : 
    Saving_account(bank_id, balance, IRATEUNBLOCKED) {}

double Unblocked_account::debit(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return amount;
    } else {
        return -1;
    }
}
