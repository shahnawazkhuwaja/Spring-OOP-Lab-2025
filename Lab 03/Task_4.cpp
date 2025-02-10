#include "iostream"
#include <string>
using namespace std;

class Laptop {
private:
    string brand;
    string model;
    string processor;
    int ram;
    int storage;
    bool isOn;

public:
    Laptop(string b, string m, string p, int r, int s) : brand(b), model(m), processor(p), ram(r), storage(s), isOn(false) {}

    void turnOn() {
        if (isOn) {
            cout << "The laptop is already on.\n";
        } else {
            isOn = true;
            cout << "The laptop is now turned on.\n";
        }
    }

    void turnOff() {
        if (!isOn) {
            cout << "The laptop is already off.\n";
        } else {
            isOn = false;
            cout << "The laptop is now turned off.\n";
        }
    }

    void runProgram(const string& program) {
        if (isOn) {
            cout << "Running " << program << " on " << brand << " " << model << ".\n";
        } else {
            cout << "The laptop is off. Turn it on first to run the program.\n";
        }
    }

    void displaySpecifications() const {
        cout << "Laptop Specifications:\n";
        cout << "Brand: " << brand << "\nModel: " << model << "\nProcessor: " << processor << "\nRAM: " << ram << " GB"<< "\nStorage: " << storage << " GB\n";
    }
};

int main() {
    Laptop ShahnawazLaptop("Dell", "Precision 5520", "Intel i7", 16, 512);
    Laptop AliLaptop("HP", "elitebook 14", "AMD Ryzen 5", 8, 256);

    cout << "Shahnawaz's Laptop:\n";
    ShahnawazLaptop.displaySpecifications();
    cout << "\nAli's Laptop:\n";
    AliLaptop.displaySpecifications();
    ShahnawazLaptop.turnOn();
    ShahnawazLaptop.runProgram("MS Word");
    ShahnawazLaptop.turnOff();

}
