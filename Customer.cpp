// Customer.cpp

#include "Customer.h"
#include <iostream>
using namespace std;

// Constructor for Customer class
Customer::Customer(int ID, const string& name, const string& address) {
    this->ID = ID;           // Initialize customer ID
    this->name = name;       // Initialize customer name
    this->address = address; // Initialize customer address
}

// Accessor method to get the customer ID
int Customer::getID() const {
    return ID;
}

// Accessor method to get the customer name
const string& Customer::getName() const {
    return name;
}

// Accessor method to get the customer address
const string& Customer::getAddress() const {
    return address;
}

// Method to print information about the customer
void Customer::printCustomerInfo() const {
    cout << "Customer ID: " << ID << endl;        // Print customer ID
    cout << "Name: " << name << endl;             // Print customer name
    cout << "Address: " << address << endl;       // Print customer address
}

// Constructor for VIPCustomer class
VIPCustomer::VIPCustomer(int ID, const string& name, const string& address, bool isVIP, const string& privileges)
    : Customer(ID, name, address), isVIP(isVIP), privileges(privileges) {}

// Method to print information about the VIP customer
void VIPCustomer::printCustomerInfo() const {
    Customer::printCustomerInfo();               // Call base class print method
    cout << "VIP Status: " << (isVIP ? "Yes" : "No") << endl;  // Print VIP status
    cout << "Privileges: " << privileges << endl;             // Print VIP privileges
}

// Constructor for BusinessCustomer class
BusinessCustomer::BusinessCustomer(int ID, const string& name, const string& address, const string& businessName, const string& businessType, const string& industry)
    : Customer(ID, name, address), businessName(businessName), businessType(businessType), industry(industry) {}

// Method to print information about the business customer
void BusinessCustomer::printCustomerInfo() const {
    Customer::printCustomerInfo();               // Call base class print method
    cout << "Business Name: " << businessName << endl;     // Print business name
    cout << "Business Type: " << businessType << endl;     // Print business type
    cout << "Industry: " << industry << endl;             // Print industry
}
