#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

// Transaction class represents a financial transaction
class Transaction {
private:
    int transactionID;      // Unique identifier for the transaction
    std::string type;       // Type of transaction (e.g., deposit, withdrawal)
    double amount;          // Amount involved in the transaction
    std::string date;       // Date of the transaction

public:
    // Constructor to initialize Transaction object
    Transaction(int transactionID, const std::string& type, double amount, const std::string& date);

    // Accessor method to get the transaction ID
    int getTransactionID() const;

    // Accessor method to get the transaction type
    const std::string& getType() const;

    // Accessor method to get the transaction amount
    double getAmount() const;

    // Accessor method to get the transaction date
    const std::string& getDate() const;

    // Method to print information about the transaction
    void printTransactionInfo() const;
};

#endif
