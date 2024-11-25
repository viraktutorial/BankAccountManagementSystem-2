#pragma once
#include <iostream>
#include "Account.cpp"

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNumber, string holder, double bal)
        : Account(accNumber, holder, bal) {}

    void display() const override {
        std::cout << "Checking Account Number: " << accountNumber
             << ", Holder: " << accountHolder
             << ", Balance: " << balance << endl;
    }
};