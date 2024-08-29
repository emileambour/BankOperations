#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Customer.h"

class Bank {
private:
    Account* accounts[100]; // Array to hold pointers to Account objects (max number of accounts: 100)
    Customer* customers[100]; // Array to hold pointers to Customer objects (max number of customers: 100)
    int numAccounts; // Number of accounts currently stored
    int numCustomers; // Number of customers currently stored
    
public:
    // Constructor for the Bank class
    Bank();

    // Destructor for the Bank class
    ~Bank();

    // Method to add an account to the bank
    void addAccount(Account* account);

    // Method to remove an account from the bank
    void removeAccount(int accountNumber);

    // Method to find an account in the bank based on account number
    Account* findAccount(int accountNumber);

    // Method to add a customer to the bank
    void addCustomer(Customer* customer);

    // Method to remove a customer from the bank
    void removeCustomer(int customerID);

    // Method to find a customer in the bank based on customer ID
    Customer* findCustomer(int customerID);

    // Method to perform a transaction on an account
    void performTransaction(int accountNumber, double amount);

    // Method to print information about all accounts in the bank
    void printAllAccounts() const;

    // Method to print information about all customers in the bank
    void printAllCustomers() const;

};

#endif
