/**
 * @file bank.hpp
 * @brief Declaration of the Bank class managing a collection of clients.
 */

#ifndef BANK_HPP
#define BANK_HPP

#include <map>
#include <iostream>

#include "client.hpp"

using namespace std;

/**
 * @class Bank
 * @brief Manages a collection of clients in the bank.
 */
class Bank {
    private:
        map<unsigned int, Client*> clients_collection; // Maps client identifiers to Client pointers
    public:
        /**
         * @brief Default constructor for the Bank class.
         */
        Bank();

        /**
         * @brief Destructor for the Bank class.
         */
        void insertClient(Client& client);

        /**
         * @brief Retrieves a client by their identifier.
         * @param id The identifier of the client to retrieve.
         * @return Pointer to the Client object if found, nullptr otherwise.
         */
        friend ostream& operator<<(ostream& o, const Bank& bank);
};

#endif