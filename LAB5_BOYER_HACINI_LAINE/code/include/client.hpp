/**
 * @file client.hpp
 * @brief Declaration of the Client class representing a bank client.
 */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>

using namespace std;

#include "account.hpp"

/**
 * @class Client
 * @brief Represents a bank client with multiple bank accounts.
*/
class Client {
    private:
        string name; // Client's name
        unsigned int identifier; // Unique identifier for the client

        Bank_account** accounts; // Array of pointers to the client's bank accounts
        size_t maxAccounts; // Maximum number of accounts the client can have
        size_t nb_currentAccounts; // Current number of accounts the client has

    public:
        /** 
         * @brief Constructor to initialize a client with name, identifier, and max accounts.
         * @param name The client's name.
         * @param identifier The unique identifier for the client.
         * @param maxAccounts The maximum number of accounts the client can have.
        */
        Client(string name, unsigned int identifier, size_t maxAccounts);

        /** 
         * @brief Copy constructor.
         * @param client The client to copy from.
        */
        Client(const Client& client);

        /** 
         * @brief Destructor to clean up allocated resources.
        */
        ~Client();
        
        /** 
         * @brief Creates a new bank account for the client if possible.
         * @return True if the account was created successfully, false otherwise.
        */
        bool createAccount();

        /** 
         * @brief Gets the client's unique identifier.
         * @return The client's identifier.
        */
        unsigned int get_id();

        /** 
         * @brief Credits a specified amount to the client's account at the given index.
         * @param idx The index of the account to credit.
         * @param amount The amount to credit.
        */
        void credit(unsigned int idx, double amount);

        /** 
         * @brief Debits a specified amount from the client's account at the given index.
         * @param idx The index of the account to debit.
         * @param amount The amount to debit.
         * @return The amount debited.
        */
        double debit(unsigned int idx, double amount);

        /** 
         * @brief Overloaded output stream operator to print client details.
         * @param o The output stream.
         * @param client The client to print.
         * @return The output stream.
        */
        friend ostream& operator<<(ostream &o, const Client& client);
};



#endif