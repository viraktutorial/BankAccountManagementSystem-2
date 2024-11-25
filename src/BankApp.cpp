#pragma once 
#include <iostream>
#include "AccountManager.cpp"
#include "Account.cpp"
#include "CheckingAccount.cpp"
#include "SavingAccount.cpp"
#include "UserAuthentication.cpp"




class BankApp{
    public:
    void run(){
        AccountManager manager;
        UserAuthentication auth;

        string username, password;
        int choice;

        try {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            // User Authentication
            if (auth.authenticate(username, password)) {
                cout << "Login successful!" << endl;

                do {
                    cout << "\nMenu:\n";
                    cout << "1. Add Account\n";
                    cout << "2. View Accounts\n";
                    cout << "3. Update Account\n";
                    cout << "4. Delete Account\n";
                    cout << "5. Search Account\n";
                    cout << "6. Sort Accounts\n";
                    cout << "7. Save Accounts to File\n";
                    cout << "8. Load Accounts from File\n";
                    cout << "9. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                    case 1: {
                        int accType, accNumber;
                        string holder;
                        double balance, rate;
                        cout << "Enter account type (1 for Saving, 2 for Checking): ";
                        cin >> accType;
                        cout << "Enter account number: ";
                        cin >> accNumber;
                        cout << "Enter account holder name: ";
                        cin >> holder;
                        cout << "Enter initial balance: ";
                        cin >> balance;
                        if (accType == 1) {
                            cout << "Enter interest rate: ";
                            cin >> rate;
                            manager.addAccount(new SavingAccount(accNumber, holder, balance, rate));
                        } else {
                            manager.addAccount(new CheckingAccount(accNumber, holder, balance));
                        }
                        break;
                    }
                    case 2:
                        manager.viewAccounts();
                        break;
                    case 3: {
                        int accNumber;
                        double newBalance;
                        cout << "Enter account number to update: ";
                        cin >> accNumber;
                        cout << "Enter new balance: ";
                        cin >> newBalance;
                        manager.updateAccount(accNumber, newBalance);
                        break;
                    }
                    case 4: {
                        int accNumber;
                        cout << "Enter account number to delete: ";
                        cin >> accNumber;
                        manager.deleteAccount(accNumber);
                        break;
                    }
                    case 5: {
                        int accNumber;
                        cout << "Enter account number to search: ";
                        cin >> accNumber;
                        manager.searchAccount(accNumber);
                        break;
                    }
                    case 6:
                        manager.sortAccounts();
                        break;
                    case 7: {
                        string filename;
                        cout << "Enter filename to save accounts: ";
                        cin >> filename;
                        manager.saveAccountsToFile(filename);
                        break;
                    }
                    case 8: {
                        string filename;
                        cout << "Enter filename to load accounts: ";
                        cin >> filename;
                        manager.loadAccountsFromFile(filename);
                        break;
                    }
                    case 9:
                        cout << "Exiting...\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                    }

                } while (choice != 9);

            } else {
                cout << "Authentication failed!" << endl;
            }

        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
};