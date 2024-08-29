// Account.cpp

#include "Account.h"

// Account Class Implementation

// Constructor for Account
Account::Account(int accountNumber, double balance) {
    this->
    accountNumber = accountNumber;
    this->balance = balance;
}

// Accessor method to get the account number
int Account::getAccountNumber() const {
    return accountNumber;
}

// Accessor method to get the account balance
double Account::getBalance() const {
    return balance;
}

// Method to deposit money into the account
void Account::deposit(double amount) {
    balance += amount;
}

// Method to withdraw money from the account
bool Account::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Error: Withdrawal amount must be positive." << std::endl;
        return false;
    }
    if (balance >= amount) {
        balance -= amount;
        return true; // Withdrawal successful
    } else {
        std::cout << "Error: Insufficient funds." << std::endl;
        return false; // Withdrawal failed
    }
}


// Method to print information about the account
void Account::printAccountInfo() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}

// Destructor for Account
Account::~Account() {}


// SavingsAccount Class Implementation

// Constructor for SavingsAccount
SavingsAccount::SavingsAccount(int accountNumber, double balance, double interestRate)
    : Account(accountNumber, balance), interestRate(interestRate), numWithdrawals(0) {}

// Method to withdraw money from the savings account
bool SavingsAccount::withdraw(double amount) {
    if (balance >= amount && numWithdrawals < 3) {
        balance -= amount;
        numWithdrawals++;
        return true; // Withdrawal successful
    } else {
        return false; // Withdrawal failed or maximum withdrawals reached
    }
}

// Method to calculate interest for the savings account
void SavingsAccount::calculateInterest() {
    double interest = balance * interestRate;
    balance += interest;
}

// Method to print information about the savings account
void SavingsAccount::printAccountInfo() const {
    std::cout << "Savings Account Number: " << getAccountNumber() << std::endl;
    std::cout << "Balance: " << getBalance() << std::endl;
    std::cout << "Interest Rate: " << interestRate << std::endl;
}


// CheckingAccount Class Implementation

// Constructor for CheckingAccount
CheckingAccount::CheckingAccount(int accountNumber, double balance, double overdraftLimit)
    : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

// Method to withdraw money from the checking account
bool CheckingAccount::withdraw(double amount) {
    if (balance + overdraftLimit >= amount) {
        balance -= amount;
        return true; // Withdrawal successful
    } else {
        return false; // Withdrawal failed
    }
}

// Method to print information about the checking account
void CheckingAccount::printAccountInfo() const {
    std::cout << "Checking Account Number: " << getAccountNumber() << std::endl;
    std::cout << "Balance: " << getBalance() << std::endl;
    std::cout << "Overdraft Limit: " << overdraftLimit << std::endl;
}
