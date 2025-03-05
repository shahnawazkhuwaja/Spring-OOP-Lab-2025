#include "iostream"
using namespace std;

class Account{

    protected:
    int accountNumber;
    float balance;

    public:
    Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

    void displayDetails(){
        cout << "------------------------------------" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account{

    private:
    float interestRate;

    public:
    SavingsAccount(int accountNumber, float balance, float interestRate) : Account(accountNumber, balance), interestRate(interestRate) {}

    void displayDetails(){
        Account :: displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account{

    private:
    float overdraftLimit;

    public:
    CheckingAccount(int accountNumber, float balance, float overdraftLimit) : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void displayDetails(){
        Account :: displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main(){
    SavingsAccount s1(240791, 500000.0, 5.5);
    CheckingAccount c1(440091, 150000.0, 10000.0);

    s1.displayDetails();
    c1.displayDetails();
}