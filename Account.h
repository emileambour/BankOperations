// Account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
protected:
    int accountNumber; // Account number
    double balance;    // Account balance

public:
    // Constructor
    Account(int accountNumber, double balance);

    // Accessor methods
    int getAccountNumber() const;
    double getBalance() const;

    // Deposit money into the account
    void deposit(double amount);

    // Withdraw money from the account
    virtual bool withdraw(double amount);

    // Print information about the account
    virtual void printAccountInfo() const;

    // Destructor
    virtual ~Account();
};

// Derived class for savings account
class SavingsAccount : public Account {
private:
    double interestRate; // Interest rate
    int numWithdrawals;  // Number of withdrawals made

public:
    // Constructor
    SavingsAccount(int accountNumber, double balance, double interestRate);

    // Overridden method to withdraw money
    bool withdraw(double amount) override;

    // Calculate and add interest to the account
    void calculateInterest();

    // Print information about the savings account
    void printAccountInfo() const override;
};

// Derived class for checking account
class CheckingAccount : public Account {
private:
    double overdraftLimit; // Overdraft limit

public:
    // Constructor
    CheckingAccount(int accountNumber, double balance, double overdraftLimit);

    // Overridden method to withdraw money
    bool withdraw(double amount) override;

    // Print information about the checking account
    void printAccountInfo() const override;
};

#endif
