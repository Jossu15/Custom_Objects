//
// Created by Lenovo on 9/02/2024.
//
#include <iostream>
#include <string>
#include <utility>

class Account{
    // String representing the name of the account's owner
    std::string name;
    // The account number
    int id;
    // The current account balance
    double balance;
public:
    // Initialize a bank account object
    Account(std::string customer_name, int account_number,
            double amount):
            name(std::move(customer_name)), id(account_number), balance(amount){
        if (amount < 0){
            std::cout << "Warning: negative account balance\n";
            balance = 0.0;
        }
    }

    // Adds amount amt to the account's balance
    void deposit(double amt){
        balance += amt;
    }
    // Deducts amount amt from the account's balance,
    // if possible.
    // returns true if successful; otherwise, it returns false.
    // A call can fail if the withdraw would
    // cause the balance to fall below zero
    bool withdraw(double amt){
        bool result = false;    // Unsuccessful by default
        if (balance - amt >= 0){
            balance -= amt;
            result = true; // Success
        }
        return result;
    }

    void display(){
        std::cout << "Name: " << name << ", ID: " << id
                  << ", Balance: " << balance << '\n';
    }
};

int main(){
    Account acct1("Joe", 2312, 1000.00);
    Account acct2("Moe", 2313, 500.29);

    acct1.display();
    acct2.display();

    std::cout << "-----------------------------" << '\n';
    acct1.withdraw(800.00);
    acct2.deposit(22);
    acct1.display();
    acct2.display();
}