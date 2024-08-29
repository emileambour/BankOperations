// Customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

// Customer Class Declaration

class Customer {
private:
    int ID;             // Unique identifier for the customer
    std::string name;   // Name of the customer
    std::string address; // Address of the customer
    
public:
    // Constructor for Customer
    Customer(int ID, const std::string& name, const std::string& address);

    // Accessor method to get the customer ID
    int getID() const;

    // Accessor method to get the customer name
    const std::string& getName() const;

    // Accessor method to get the customer address
    const std::string& getAddress() const;

    // Method to print information about the customer
    void printCustomerInfo() const;
};

// VIPCustomer Class Declaration (Derived from Customer)

class VIPCustomer : public Customer {
private:
    bool isVIP;             // Flag indicating if the customer is a VIP
    std::string privileges; // Privileges associated with VIP status

public:
    // Constructor for VIPCustomer
    VIPCustomer(int ID, const std::string& name, const std::string& address, bool isVIP, const std::string& privileges);

    // Method to print information about the VIP customer
    void printCustomerInfo() const;
};

// BusinessCustomer Class Declaration (Derived from Customer)

class BusinessCustomer : public Customer {
private:
    std::string businessName;   // Name of the business associated with the customer
    std::string businessType;   // Type of business
    std::string industry;       // Industry of the business
    
public:
    // Constructor for BusinessCustomer
    BusinessCustomer(int ID, const std::string& name, const std::string& address, const std::string& businessName, const std::string& businessType, const std::string& industry);

    // Method to print information about the business customer
    void printCustomerInfo() const;

};

#endif // CUSTOMER_H
