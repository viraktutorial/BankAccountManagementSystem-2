#pragma once
#include <iostream>
#include "Account.cpp"
#include "AccountManager.cpp"
#include "CheckingAccount.cpp"

class UserAuthentication {
private:
    string username;
    string password;

public:
    bool authenticate(const string &inputUsername, const string &inputPassword) {
        // Hardcoded username and password (for simplicity)
        username = "admin";
        password = "admin123";

        if (inputUsername == username && inputPassword == password) {
            return true;
        } else {
            throw runtime_error("Invalid credentials!");
        }
    }
};