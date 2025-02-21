#include "iostream"
using namespace std;

class Battery {
    int capacity;

public:
    Battery(int cap) :capacity(cap){}

    void display() const {
        cout << "Battery Capacity: " << capacity << " mAh" << endl;
    }
};

class Smartphone {
    string model;
    Battery battery;

public:
    Smartphone(string modelName, int batteryCapacity):model(modelName), battery(batteryCapacity){}

    void display() const {
        cout << "Smartphone Model: " << model << endl;
        battery.display();
    }
};

int main() {
    Smartphone phone1("Samsung S25 Ultra", 5000);
    Smartphone phone2("iPhone 16 Pro Max", 4500);

    cout << "Smartphone 1 Details:\n";
    phone1.display();
    cout << "\nSmartphone 2 Details:\n";
    phone2.display();
}