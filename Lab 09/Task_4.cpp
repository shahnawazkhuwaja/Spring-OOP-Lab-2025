#include "iostream"
#include <string>
using namespace std;

class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;

public:
    CreditCard(string number) {
        cardNumber = number;
    }

    bool processPayment(double amount){
        if (amount > 0) {
            cout << "Payment of PKR" << amount << " processed using Credit Card: " << cardNumber << endl;
            return true;
        } else {
            cout << "Invalid amount for credit card payment." << endl;
            return false;
        }
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;

public:
    DigitalWallet(double initialBalance) {
        balance = initialBalance;
    }

    bool processPayment(double amount){
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Payment of PKR" << amount << " processed using Digital Wallet." << endl;
            cout << "Remaining balance: PKR" << balance << endl;
            return true;
        } else {
            cout << "Payment failed. Insufficient balance or invalid amount." << endl;
            return false;
        }
    }
};

int main() {

    CreditCard myCard("0000-1234-5678-0000");
    DigitalWallet myWallet(100000.0);

    cout << "\n--- Credit Card Payment ---" << endl;
    myCard.processPayment(5000.0);
    myCard.processPayment(-1000.0);

    cout << "\n--- Digital Wallet Payment ---" << endl;
    myWallet.processPayment(4000.0);
    myWallet.processPayment(7000.0);
return 0;
}