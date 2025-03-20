#include "iostream"
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;
    string accountType;

public:
    Account(int accNum, string name, double bal, string type)
        : accountNumber(accNum), accountHolderName(name), balance(bal), accountType(type) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount>0 && amount<=balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " New balance: " << balance << endl;
        } else {
            cout <<"Invalid/insufficient Balance" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Not available for base account." << endl;
    }

    virtual void printStatement() {
        cout << "Account Statement:\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolderName << "\n";
        cout << "Balance: " << balance << "\n";
        cout << "Account Type: " << accountType << "\n";
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, string name, double bal, double rate, double minBal)
        : Account(accNum, name, bal, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance*(interestRate/ 100);
        balance += interest;
        cout << "Interest Added: " << interest << " New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance-amount>= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw. No Minimum Balance" << endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, string name, double bal)
        : Account(accNum, name, bal, "Checking") {}

    void withdraw(double amount) override {
        Account::withdraw(amount);
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(int accNum, string name, double bal, double rate, int maturity)
        : Account(accNum, name, bal, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest() override {
        double interest =balance*(fixedInterestRate/ 100);
        cout << "Fixed Deposit Interest: " << interest << " (Not added yet, matures on date " << maturityDate << ")" << endl;
    }

    void withdraw(double amount) override {
        amount = 0;
        cout << "Amount: " << amount << endl;
        cout << "Withdrawals are not allowed before maturity!" << endl;
    }
};

int main() {
    SavingsAccount s1(123, "Shahnawaz Khuwaja", 50000, 4, 10000);
    CheckingAccount c1(234, "Ali", 350000);
    FixedDepositAccount f1(432, "Ahmed", 125000, 6, 2027);

    s1.printStatement();
    s1.deposit(15000);
    s1.withdraw(23000);
    s1.calculateInterest();
    cout << "\n";
    c1.printStatement();
    c1.withdraw(12000);
    cout << "\n";
    f1.printStatement();
    f1.calculateInterest();
    f1.withdraw(33000);
return 0;
}