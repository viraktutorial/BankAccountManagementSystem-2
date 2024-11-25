#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>

using namespace std;


// Account base class
class Account {
protected:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    Account(int accNumber, string holder, double bal)
        : accountNumber(accNumber), accountHolder(holder), balance(bal) {}

    int getAccountNumber() const { 
        return accountNumber; 
    }
    string getAccountHolder() const { 
        return accountHolder; 
    }
    double getBalance() const { 
        return balance; 
    }
    void setBalance(double newBalance) { 
        balance = newBalance; 
    }

    virtual void deposit(double amount) {
        if (amount <= 0) throw invalid_argument("Deposit amount must be positive.");
        balance += amount;
    }
    virtual void withdraw(double amount) {
        if (amount <= 0) throw invalid_argument("Withdrawal amount must be positive.");
        if (amount > balance) throw runtime_error("Insufficient funds.");
        balance -= amount;
    }
    virtual void display() const = 0; // Pure virtual function

};


