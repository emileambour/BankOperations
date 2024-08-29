#include "Bank.h"
#include <iostream>

// Constructor for the Bank class
Bank::Bank() {
    numAccounts = 0;
    numCustomers = 0;
}

// Destructor for the Bank class
Bank::~Bank() {}

// Method to add an account to the bank
void Bank::addAccount(Account* account) {
    if (numAccounts < 100) { // Ensure not exceeding the maximum number of accounts
        accounts[numAccounts++] = account;
    } else {
        std::cout << "Cannot add more accounts. Bank is full." << std::endl;
    }
}

// Method to remove an account from the bank
void Bank::removeAccount(int accountNumber) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            delete accounts[i];
            // Shift elements to fill the gap left by removed account
            for (int j = i; j < numAccounts - 1; ++j) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            std::cout << "Account with number " << accountNumber << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Account with number " << accountNumber << " not found." << std::endl;
}

// Method to find an account in the bank based on account number
Account* Bank::findAccount(int accountNumber) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            return accounts[i];
        }
    }
    return nullptr; // Account not found
}

// Method to add a customer to the bank
void Bank::addCustomer(Customer* customer) {
    if (numCustomers < 100) { // Ensure not exceeding the maximum number of customers
        customers[numCustomers++] = customer;
    } else {
        std::cout << "Cannot add more customers. Bank is full." << std::endl;
    }
}

// Method to remove a customer from the bank
void Bank::removeCustomer(int customerID) {
    for (int i = 0; i < numCustomers; ++i) {
        if (customers[i]->getID() == customerID) {
            delete customers[i];
            // Shift elements to fill the gap left by removed customer
            for (int j = i; j < numCustomers - 1; ++j) {
                customers[j] = customers[j + 1];
            }
            numCustomers--;
            std::cout << "Customer with ID " << customerID << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Customer with ID " << customerID << " not found." << std::endl;
}

// Method to find a customer in the bank based on customer ID
Customer* Bank::findCustomer(int customerID) {
    for (int i = 0; i < numCustomers; ++i) {
        if (customers[i]->getID() == customerID) {
            return customers[i];
        }
    }
    return nullptr; // Customer not found
}

// Method to perform a transaction on an account
void Bank::performTransaction(int accountNumber, double amount) {
    Account* acc = findAccount(accountNumber);
    if (acc != nullptr) {
        if (amount > 0) {
            acc->deposit(amount);
            std::cout << "Deposit of " << amount << " successfully made to account number " << accountNumber << std::endl;
        } else {
            bool success = acc->withdraw(-amount);
            if (success) {
                std::cout << "Withdrawal of " << -amount << " successfully made from account number " << accountNumber << std::endl;
            } else {
                std::cout << "Failed to withdraw " << -amount << " from account number " << accountNumber << ". Insufficient funds." << std::endl;
            }
        }
    } else {
        std::cout << "Account with number " << accountNumber << " not found." << std::endl;
    }
}

// Method to print information about all accounts in the bank
void Bank::printAllAccounts() const {
    std::cout << "Accounts in the bank:" << std::endl;
    for (int i = 0; i < numAccounts; ++i) {
        accounts[i]->printAccountInfo();
    }
}

// Method to print information about all customers in the bank
void Bank::printAllCustomers() const {
    std::cout << "Customers of the bank:" << std::endl;
    for (int i = 0; i < numCustomers; ++i) {
        std::cout << "Customer ID: " << customers[i]->getID() << std::endl;
        std::cout << "Name: " << customers[i]->getName() << std::endl;
        std::cout << "Address: " << customers[i]->getAddress() << std::endl;
        std::cout << std::endl;
    }
}
