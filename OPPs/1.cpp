#include <iostream>
using namespace std;

// Abstract Class (Abstraction)
class Account {
protected:
    string owner;
    double balance;

public:
    Account(string owner, double balance) : owner(owner), balance(balance) {}

    // Virtual function for polymorphism
    virtual void display() const = 0;

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual ~Account() {}
};

// Derived Class (Inheritance)
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string owner, double balance, double rate)
        : Account(owner, balance), interestRate(rate) {}

    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Added: " << interest << " | New Balance: " << balance << endl;
    }

    void display() const override {
        cout << "Savings Account - Owner: " << owner << ", Balance: " << balance << endl;
    }
};

// Derived Class (Inheritance + Polymorphism)
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(string owner, double balance, double limit)
        : Account(owner, balance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Exceeded overdraft limit!" << endl;
        }
    }

    void display() const override {
        cout << "Current Account - Owner: " << owner << ", Balance: " << balance << endl;
    }
};

int main() {
    // Using polymorphism with pointers
    Account *acc1 = new SavingsAccount("Alice", 5000, 5);
    Account *acc2 = new CurrentAccount("Bob", 3000, 1000);

    acc1->display();
    acc1->deposit(1000);
    acc1->withdraw(2000);
    dynamic_cast<SavingsAccount *>(acc1)->addInterest();

    cout << "\n";

    acc2->display();
    acc2->deposit(500);
    acc2->withdraw(4000);

    // Clean up
    delete acc1;
    delete acc2;

    return 0;
}
