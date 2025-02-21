#include "iostream"
#include <cstring>
using namespace std;

class Car {
    string registrationNumber;
    string modelName;
    string ownerName;

public:
    Car(string regNum, string model, string owner):registrationNumber(regNum), modelName(model), ownerName(owner) {}

    Car(const Car &original, string newOwner) {
        registrationNumber = original.registrationNumber;
        modelName = original.modelName;
        ownerName = newOwner;
    }

    void display() {
        cout << "Car Details: " << endl;
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Model: " << modelName << endl;
        cout << "Owner: " << ownerName << endl;
    }
};

int main() {
    Car car1("BDA-234", "Toyota Corolla Grande", "Shahnawaz Khuwaja");
    cout << "Original Car:\n";
    car1.display();
    Car car2(car1, "Ali");
    cout << "\nCopied Car with New Owner:\n";
    car2.display();
}