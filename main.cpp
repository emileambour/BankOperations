// main.cpp

#include <iostream>
#include "Account.h"
#include "Customer.h"
#include "Transaction.h"
#include "Bank.h"

int main() {
    // Create some accounts
    Account* acc1 = new SavingsAccount(1001, 5000.0, 0.05);
    Account* acc2 = new CheckingAccount(1002, 3000.0, 1000.0);
    
    // Create some customers
    Customer* cust1 = new VIPCustomer(2001, "John Doe", "123 Main St", true, "VIP Lounge Access");
    Customer* cust2 = new BusinessCustomer(2002, "Jane Smith", "456 Broadway", "Smith Enterprises", "Retail", "Fashion");
    
    // Create a bank
    Bank bank;
    
    // Add accounts to the bank
    bank.addAccount(acc1);
    bank.addAccount(acc2);
    
    // Add customers to the bank
    bank.addCustomer(cust1);
    bank.addCustomer(cust2);
    
    // Perform transactions
    bank.performTransaction(1001, -1000.0); // Withdraw $1000 from account 1001
    bank.performTransaction(1002, 2000.0); // Deposit $2000 into account 1002
    
    // Print information about all accounts in the bank
    bank.printAllAccounts();
    
    // Print information about all customers in the bank
    bank.printAllCustomers();
    
    // Clean up
    delete acc1;
    delete acc2;
    delete cust1;
    delete cust2;
    
    return 0;
}