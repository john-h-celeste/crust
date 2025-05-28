#include <iostream>

class Account {
private:
    int id; // account ID
    double balance; // Current balance in dollars
    double annualInterestRate; // Fraction of current balance earned annually - 0.12 is 12%

public:
    Account(int id_, double balance_, double annualInterestRate_) {
        setId(id_);
        setBalance(balance_);
        setAnnualInterestRate(annualInterestRate_);
    }

    // Get the ID
    int getId() {
        return id;
    }

    // Get the current balance
    double getBalance() {
        return balance;
    }

    // Set the account ID
    // If `newId` is negative, set the ID to zero
    void setId(int newId) {
        id = newId;
        if (id < 0) {
            id = 0;
        }
    }

    // Set the current balance
    // If `newBalance` is negative, set the balance to zero
    void setBalance(double newBalance) {
        balance = newBalance;
        if (balance < 0) {
            balance = 0;
        }
    }

    // Set the annual interest rate
    // `newAnnualInterestRate` is a simple multiplier: 0.12 = 12%
    // If `newAnnualInterestRate` is negative, set the interest rate to zero
    void setAnnualInterestRate(double newAnnualInterestRate) {
        annualInterestRate = newAnnualInterestRate;
        if (annualInterestRate < 0) {
            annualInterestRate = 0;
        }
    }

    // Returns the amount of interest per month
    // Calculated with simple interest
    double getMonthlyInterest() {
        return balance * annualInterestRate / 12;
    }

    // Attempt to withdraw `amount` dollars (subtract from balance)
    // If `amount` is greater than the balance, print a message instead
    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Not enough money to withdraw $" << amount << std::endl;
            return;
        }
        balance -= amount;
    }

    // Deposit `amount` dollars (add to balance)
    void deposit(double amount) {
        balance += amount;
    }
};

int main() {
    Account account(0, 20000, 0.045);

    account.withdraw(25000);
    account.deposit(3000);
    std::cout << "The ID is " << account.getId() << std::endl;
    std::cout << "The current balance is $" << account.getBalance() << std::endl;
    std::cout << "The current monthly interest is $" << account.getMonthlyInterest() << std::endl;
}