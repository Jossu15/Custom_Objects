//
// Created by Lenovo on 9/02/2024.
//
#include <iostream>

class Account{
    // String representing the name of the account's owner
    std::string name;
    // The account number
    int id;
    // The current account balance
    double balance;
public:

    void deposit(double amt){
        balance += amt;
    }

    bool withdraw(double amt){
        bool result = false; // Unsuccessful by default
        if (balance - amt >= 0){
            balance -= amt;
            result = true; // Success
        }
        return result;
    }
};
