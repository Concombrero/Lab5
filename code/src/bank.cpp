/**
 * @file bank.cpp
 * @brief Implementation of the Bank class.
 */

#include "bank.hpp"

Bank::Bank() {}

void Bank::insertClient(Client& client) {
    clients_collection[client.get_id()] = &client;
}

ostream& operator<<(ostream& o, const Bank& bank) {
    for (map<unsigned int, Client*>::const_iterator i = bank.clients_collection.begin(); i != bank.clients_collection.end(); i++) {
        o << "CLIENT [" << *(*i).second << "]" << endl;
    }
    return o;
}
