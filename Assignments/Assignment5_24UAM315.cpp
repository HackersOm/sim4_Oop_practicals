#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Bank {
public:
    void deposit(int amount) {
        cout << "Depositing ₹" << amount << "          in cash." << endl;
   
    }

    void deposit(double amount) {
        cout << "Depositing ₹" << fixed <<         setprecision(2) << amount << " via digital payment." << endl;
        
    }

    void deposit(int amount, const string& upiId) {
        cout << "Depositing ₹" << amount << " using UPI (" << upiId << ")." << endl;
       
    }
};

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    Account operator+(const Account& other) {
        return Account(other.accountNumber, other.balance + balance);
    }
    Account operator-(double withdrawAmount){
        return Account(accountNumber, balance - withdrawAmount);
    }

    void transferFunds(Account& recipient, double amount) {
        if (balance >= amount) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transferring ₹" << fixed << setprecision(2) << amount << " from Account " << accountNumber << " to Account " << recipient.accountNumber << "..." << endl;
        } else {
            cout << "Insufficient funds for transfer." << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "Account " << accountNumber << " Balance: ₹" << fixed << setprecision(2) << balance << endl;
    }

    double getBalance() const {
        return balance;
    }
    void setBalance(double newBalance){
        balance = newBalance;
    }

    int getAccountNumber() const{
        return accountNumber;
    }
};

int main() {
    Bank indianBank;
    indianBank.deposit(5000);
    indianBank.deposit(1500.75);
    indianBank.deposit(2500, "gpay@upi");

    Account account1(101, 10000.00);
    Account account2(102, 5000.00);

    account1.displayAccountDetails();
    account2.displayAccountDetails();

    account1.transferFunds(account2, 3000.00);

    account1.displayAccountDetails();
    account2.displayAccountDetails();

    account1.setBalance(account1.getBalance() - 2000.00);
    cout << "Withdrawing ₹2000 from Account " << account1.getAccountNumber() << "..." <<endl;
    cout << "Remaining Balance: ₹" << fixed << setprecision(2) << account1.getBalance() << endl;

    return 0;
}