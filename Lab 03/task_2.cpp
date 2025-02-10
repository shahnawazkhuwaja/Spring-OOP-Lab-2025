#include "iostream"
#include <string>
using namespace std;

class TeaMug {
private:
    string brand, color;
    int capacity, currentFillLevel;

public:
    TeaMug(string b, string c, int cap, int fill) : brand(b), color(c), capacity(cap), currentFillLevel(fill) {}

    void sipTea(int amount) {
        if (currentFillLevel >= amount) {
            currentFillLevel -= amount;
            cout << "Sipped tea. Current fill level: " << currentFillLevel << "ml\n";
        } else {
            cout << "Not enough tea left. Please refill the mug.\n";
        }
    }

    void refill() {
        currentFillLevel = capacity;
        cout << "Mug refilled. Current fill level: " << currentFillLevel << "ml\n";
    }

    void checkIfEmpty() const {
        if (currentFillLevel == 0) {
            cout << "The mug is empty.\n";
        } else {
            cout << "The mug is not empty. Current fill level: " << currentFillLevel << "ml\n";
        }
    }

    void displayDetails() const {
        cout << "Mug Brand: " << brand << ", Color: " << color << ", Capacity: " << capacity << "ml, Current Fill Level: " << currentFillLevel << "ml\n";
    }
};

int main() {
    TeaMug mug("Thermos", "Black", 300, 150);
    mug.displayDetails();
    mug.sipTea(50);
    mug.sipTea(120);
    mug.checkIfEmpty();
    mug.refill();
}
