//
// Created by Lenovo on 8/02/2024.
//
#include <iostream>
#include <vector>
#include <string>

class Account{
public:
    std::string name; // the name of the account's owner
    int id{};           // The account number
    double balance{};   // The current account balance
};

// Allows the user to enter via the keyboard information
// About an account and adds that account to the database.
void add_account(std::vector<Account>& accts){
    std::string name;
    int number;
    double amount;

    std::cout << "Enter name, account number, and account balance: ";
    std::cin >> name >> number >> amount;
    Account acct;
    acct.name = name;
    acct.id = number;
    acct.balance = amount;
    accts.push_back(acct);
}

// Print all the accounts in the database
void print_accounts(const std::vector<Account>& accts){
    int n = static_cast<int>(accts.size());
    for (int i = 0; i < n; i++)
        std::cout << accts[i].name << "," << accts[i].id
                  << "," << accts[i].balance << '\n';
}

void swap(Account& er1, Account& er2){
    Account temp = er1;
    er1 = er2;
    er2 = temp;
}

bool less_than_by_name(const Account& e1, const Account& e2){
    return e1.name < e2.name;
}


bool less_than_by_id(const Account& e1, const Account& e2){
    return e1.id < e2.id;
}


bool less_than_by_balance(const Account& e1, const Account& e2){
    return e1.balance < e2.balance;
}

// Sorts a bank account database into ascending order
// The comp parameter determines the ordering
void sort(std::vector<Account>& db,
          bool (*comp)(const Account&, const Account&)){
    int size = static_cast<int>(db.size());
    for (int i = 0; i < size - 1; i++){
        int smallest = i;
        for (int j = i + 1; j < size; j++)
            if(comp(db[j], db[smallest]))
                smallest = j;
        if (smallest != i)
            swap(db[i], db[smallest]);
    }
}

// Allows a user interact with a bank account database.
int main(){
    // The simple database of bank accounts
    std::vector<Account> customers;

    // User command
    char cmd;

    // Are we done yet?
    bool done = false;

    do {
        std::cout << "[A]dd [N]ame [I]D [B]alance [Q]uit==> ";
        std::cin >> cmd;
        switch (cmd) {
            case 'A':
            case 'a':
                // Add an account
                add_account(customers);
                break;
            case 'P':
            case 'p':
                // Print customer database
                print_accounts(customers);
                break;
            case 'N':
            case 'n':
                // Sort database by name
                sort(customers, less_than_by_name);
                print_accounts(customers);
                break;
            case 'I':
            case 'i':
                // Sort database by ID (account number)
                sort(customers, less_than_by_id);
                print_accounts(customers);
                break;
            case 'B':
            case 'b':
                // Sort database by account balance
                sort(customers, less_than_by_balance);
                print_accounts(customers);
                break;
            case 'Q':
            case 'q':
                done = true;
                break;
            default:
                break;
        }
    }
    while(!done);
}