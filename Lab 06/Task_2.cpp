#include "iostream"
using namespace std;

class Vehicle{

    protected:
    string brand;
    int speed;

    public:
    Vehicle(string brand, int speed) : brand(brand), speed(speed) {}

    void displayDetails(){
        cout << "----------------------------------" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
    }
};

class Car : public Vehicle{

    protected:
    int seats;

    public:
    Car(string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displayDetails(){
        Vehicle :: displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car{

    private:
    int batteryLife;

    public:
    ElectricCar(string brand, int speed, int seats, int batteryLife) :
                Car(brand, speed, seats), batteryLife(batteryLife) {}

    void displayDetails(){
        Car :: displayDetails();
        cout << "Battery Life: " << batteryLife << endl;
    }
};

int main(){
    ElectricCar c1("Tesla Model S", 320, 4, 95);
    c1.displayDetails();
}