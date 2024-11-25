#pragma once
#include <iostream>
#include "Account.cpp"

class AccountManager {
private:
    vector<Account*> accounts;

    Account* findAccount(int accountNumber) {
        for (auto account : accounts) {
            if (account->getAccountNumber() == accountNumber) {
                return account;
            }
        }
        return nullptr;
    }

public:
    void addAccount(Account *account) {
        accounts.push_back(account);
    }

    void viewAccounts() const {
        if (accounts.empty()) {
            std::cout << "No accounts available." << endl;
            return;
        }
        for (const auto &acc : accounts) {
            acc->display();
        }
    }

    void updateAccount(int accNumber, double newBalance) {
        Account* acc = findAccount(accNumber);
        if (acc) {
            acc->setBalance(newBalance);
            std::cout << "Account updated successfully." << endl;
        } else {
            std::cout << "Account not found!" << endl;
        }
    }

    void deleteAccount(int accNumber) {
        auto it = remove_if(accounts.begin(), accounts.end(), [accNumber](Account* acc) {
            return acc->getAccountNumber() == accNumber;
        });
        if (it != accounts.end()) {
            accounts.erase(it, accounts.end());
            cout << "Account deleted successfully." << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void searchAccount(int accNumber) {
        Account* acc = findAccount(accNumber);
        if (acc) {
            acc->display();
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void sortAccounts() {
        sort(accounts.begin(), accounts.end(), [](Account* a, Account* b) {
            return a->getBalance() > b->getBalance();
        });
        cout << "Accounts sorted by balance in descending order." << endl;
    }
    void saveAccountsToFile(const string &filename) const {
        string filePath = "../data/" + filename;
        ofstream file(filePath, ios::binary);
        if (!file) {
            throw runtime_error("Failed to open file for writing.");
        }

        for (const auto &acc : accounts) {
            file.write(reinterpret_cast<const char*>(&acc), sizeof(Account*));
        }
        file.close();
    }

    void loadAccountsFromFile(const string &filename) {
        string filePath = "../data/" + filename;
        ifstream file(filePath, ios::binary);
        if (!file) {
            throw runtime_error("Failed to open file for reading.");
        }

        while (file) {
            Account* acc;
            file.read(reinterpret_cast<char*>(&acc), sizeof(Account*));
            if (file) {
                accounts.push_back(acc);
            }
        }
        file.close();
    }
};
