#include "iostream"
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() {
        return amount*exchangeRate;
    }

    virtual double convertTo(Currency& targetCurrency) {
        double baseAmount = convertToBase();
        return baseAmount/targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() override {
        cout << "$" << amount << " (USD)" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    void displayCurrency() override {
        cout << "E" << amount << " (EUR)" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}

    void displayCurrency() override {
        cout << "INR" << amount << " (INR)" << endl;
    }
};

int main() {
    Dollar usd(200);
    Euro eur(140);
    Rupee inr(3500);

    cout << "Currency Details:\n";
    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    cout << "\nConversions:\n";
    cout << "$200 in EUR: " << usd.convertTo(eur) << " EUR\n";
    cout << "E140 in USD: " << eur.convertTo(usd) << " USD\n";
    cout << "INR3500 in USD: " << inr.convertTo(usd) << " USD\n";
return 0;
}