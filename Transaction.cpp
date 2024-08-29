#include "Transaction.h"
#include <iostream>

// Constructor to initialize Transaction object
Transaction::Transaction(int transactionID, const std::string& type, double amount, const std::string& date) {
    this->transactionID = transactionID;
    this->type = type;
    this->amount = amount;
    this->date = date;
}

// Accessor method to get the transaction ID
int Transaction::getTransactionID() const {
    return transactionID;
}

// Accessor method to get the transaction type
const std::string& Transaction::getType() const {
    return type;
}

// Accessor method to get the transaction amount
double Transaction::getAmount() const {
    return amount;
}

// Accessor method to get the transaction date
const std::string& Transaction::getDate() const {
    return date;
}

// Method to print information about the transaction
void Transaction::printTransactionInfo() const {
    std::cout << "Transaction ID: " << transactionID << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Date: " << date << std::endl;
}
