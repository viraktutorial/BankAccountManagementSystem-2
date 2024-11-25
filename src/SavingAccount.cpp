#pragma once
#include <iostream>
#include "Account.cpp"


class SavingAccount : public Account {
private:
    double interestRate;
public:
    SavingAccount(int accNumber, string holder, double bal, double rate)
        : Account(accNumber, holder, bal), interestRate(rate) {}

    void display() const override {
        std::cout << "Saving Account Number: " << accountNumber
             << ", Holder: " << accountHolder
             << ", Balance: " << balance
             << ", Interest Rate: " << interestRate << "%" << endl;
    }
};