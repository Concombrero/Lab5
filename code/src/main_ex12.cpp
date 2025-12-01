/**
 * @file main.cpp
 * @brief Main program to demonstrate the Bank and Client classes.
 */

#include <iostream>
#include <fstream>

#include "bank.hpp"
#include "client.hpp"

using namespace std;

int main() {
    ofstream outputFile("bin/output.txt");
    
    if (!outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    Bank my_bank;

    // Smith
    Client smith("Smith", 1234, 10);

    cout << "Creation of accounts for Smith:" << endl;
    outputFile << "Creation of accounts for Smith:" << endl;
    
    smith.createAccount();
    smith.credit(0, 1000.0);

    smith.createAccount();
    smith.credit(1, 2000.0);

    smith.createAccount();
    smith.credit(2, 3000.0);

    smith.debit(1, 100.0);

    my_bank.insertClient(smith);

    outputFile << endl << "--- Final Bank Status ---" << endl;
    outputFile << my_bank << endl;


    // Emma
    cout << "\nCreation of Accounts for Emma:" << endl;
    outputFile << "\nCreation of Accounts for Emma:" << endl;
    
    Client emma("Emma", 5678, 5);

    emma.createAccount();
    emma.credit(0, 500.0);

    emma.createAccount();
    emma.credit(1, 1500.0);

    emma.createAccount();
    emma.credit(2, 10000.0);

    emma.debit(0, 800.0);
    emma.debit(1, 100.0);
    emma.debit(2, 600.0);

    my_bank.insertClient(emma);

    smith.debit(0, 200.0);

    emma.createAccount();
    emma.createAccount();
    emma.createAccount();

    outputFile << endl << "--- Final Bank Status ---" << endl;
    outputFile << my_bank << endl;

    outputFile.close();

    return 0;
}