#include <iostream>
#include <string>
#include <exception>
using namespace std;

class InsufficientFundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient funds!";
    }
};

class InvalidTransactionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid transaction!";
    }
};

class DivideByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Cannot divide by zero!";
    }
};

class BankAccount {
private:
    string ownerName;
    double balance;

public:
    BankAccount(string name, double initialDeposit) {
        ownerName = name;
        if (initialDeposit < 0) {
            throw InvalidTransactionException();  // Invalid deposit amount
        }
        balance = initialDeposit;
        cout << "Creating Account for " << ownerName << " with Initial Deposit: Rs. " << balance << endl;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidTransactionException();  // Invalid deposit amount
        }
        balance += amount;
        cout << "Depositing Rs. " << amount << " into " << ownerName << "'s Account" << endl;
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidTransactionException();  // Invalid withdrawal amount
        }
        if (amount > balance) {
            throw InsufficientFundsException();  // Not enough balance
        }
        balance -= amount;
        cout << "Withdrawing Rs. " << amount << " from " << ownerName << "'s Account" << endl;
    }

    // Method to transfer money between accounts
    void transfer(BankAccount &to, double amount) {
        if (amount <= 0) {
            throw InvalidTransactionException();  // Invalid transfer amount
        }
        if (amount > balance) {
            throw InsufficientFundsException();  // Not enough balance
        }
        balance -= amount;
        to.balance += amount;
        cout << "Transferring Rs. " << amount << " from " << ownerName << " to " << to.ownerName << endl;
    }

    void divideBalance(double divisor) {
        if (divisor == 0) {
            throw DivideByZeroException();  // Dividing by zero
        }
        balance /= divisor;
        cout << "Dividing balance by " << divisor << ". New balance: Rs. " << balance << endl;
    }

    // Method to display account details
    void display() {
        cout << "Account Holder: " << ownerName << ", Balance: Rs. " << balance << endl;
    }
};

int main() {
    try {
        // Creating accounts
        BankAccount rahul("Rahul Sharma", 5000);
        BankAccount priya("Priya Verma", 2000);

        rahul.deposit(1000);
        rahul.withdraw(7000);  

    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    } catch (const InvalidTransactionException& e) {
        cout << e.what() << endl;
    } catch (const DivideByZeroException& e) {
        cout << e.what() << endl;
    } catch (const std::exception& e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    try {
        BankAccount rahul("Rahul Sharma", 5000);
        BankAccount priya("Priya Verma", 2000);

        rahul.transfer(priya, 3000);
        rahul.display();
        priya.display();

        rahul.divideBalance(0); 

    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    } catch (const InvalidTransactionException& e) {
        cout << e.what() << endl;
    } catch (const DivideByZeroException& e) {
        cout << e.what() << endl;
    }

    return 0;
    
}
