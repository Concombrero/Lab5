/**
 * @file account.hpp
 * @brief Declaration of Bank_account and its derived classes.
 */

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
using namespace std;

#define IRATEBLOCKED 4
#define IRATEUNBLOCKED 2

/**
 * @class Bank_account
 * @brief Abstract base class representing a bank account.
 */
class Bank_account {
    private:
        unsigned int bank_id; // Unique identifier for the bank account
    protected:
        double balance; // Current balance of the account
    public:
        /** 
         * @brief Constructor to initialize bank account with ID and balance.
         * @param bank_id The unique identifier for the bank account.
         * @param balance The initial balance of the account.
        */
        Bank_account(unsigned int bank_id, double balance);

        /** 
         * @brief Virtual destructor.
        */
        virtual ~Bank_account() = default;

        /** 
         * @brief Credit the account with a specified amount.
         * @param amount The amount to credit.
        */
        void credit(double amount);

        /** 
         * @brief Pure virtual function to debit the account by a specified amount.
         * @param amount The amount to debit.
         * @return The actual debited amount.
        */
        virtual double debit(double amount) = 0;

        /** 
         * @brief Function call operator to get the bank ID.
         * @return The bank ID.
        */
        unsigned int operator()() const;

        /** 
         * @brief Pure virtual function to print account details.
         * @param o The output stream.
        */
        virtual void print(ostream &o) const = 0;
};

/** 
 * @brief Overloaded output stream operator for Bank_account.
 * @param o The output stream.
 * @param account The bank account to print.
 * @return The output stream.
*/
ostream& operator<<(ostream &o, const Bank_account &account);

/** 
 * @class Current_account
 * @brief Class representing a current bank account.
 */
class Current_account : public Bank_account {
    public:
        /** 
         * @brief Constructor to initialize current account with ID and balance.
         * @param bank_id The unique identifier for the bank account.
         * @param balance The initial balance of the account.
        */
        Current_account(unsigned int bank_id, double balance);

        /** 
         * @brief Debit the account by a specified amount.
         * @param amount The amount to debit.
         * @return The actual debited amount.
        */
        double debit(double amount) override;

        /** 
         * @brief Print account details.
         * @param o The output stream.
        */
        void print(ostream &o) const override;
};

/** 
 * @class Saving_account
 * @brief Class representing a saving bank account.
 */
class Saving_account : public Bank_account {
    protected:
        double interest_rate; // Interest rate for the saving account
    public:
        /** 
         * @brief Constructor to initialize saving account with ID, balance, and interest rate.
         * @param bank_id The unique identifier for the bank account.
         * @param balance The initial balance of the account.
         * @param interest_rate The interest rate for the account.
        */
        Saving_account(unsigned int bank_id, double balance, double interest_rate);
        /** 
         * @brief Print account details.
         * @param o The output stream.
        */
        void print(ostream &o) const override;

        /** 
         * @brief Add interest to the account balance.
         * @param interest The interest rate to be added.
        */
        void add_interest(double interest);
};

/** 
 * @class Blocked_account
 * @brief Class representing a blocked saving bank account.
 */
class Blocked_account : public Saving_account {
    public:
        /** 
         * @brief Constructor to initialize blocked account with ID and balance.
         * @param bank_id The unique identifier for the bank account.
         * @param balance The initial balance of the account.
        */
        Blocked_account(unsigned int bank_id, double balance);

        /** 
         * @brief Debit operation is not allowed for blocked accounts.
         * @param amount The amount to debit (unused).
         * @return Always returns 0.
        */
        double debit([[maybe_unused]] double amount) override;
};

/** 
 * @class Unblocked_account
 * @brief Class representing an unblocked saving bank account.
 */
class Unblocked_account : public Saving_account {
    public:
        /** 
         * @brief Constructor to initialize unblocked account with ID and balance.
         * @param bank_id The unique identifier for the bank account.
         * @param balance The initial balance of the account.
        */
        Unblocked_account(unsigned int bank_id, double balance);

        /** 
         * @brief Debit the account by a specified amount.
         * @param amount The amount to debit.
         * @return The actual debited amount.
        */
        double debit(double amount) override;
};

#endif
