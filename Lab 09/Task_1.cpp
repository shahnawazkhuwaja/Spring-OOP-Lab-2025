#include "iostream"
using namespace std;

class Vehicle{
    private:
    string model;
    double rate;

    public:
    virtual void getDailyRate(double rate) = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle{
    private:
    string model;
    double rate;

    public:
    Car(string model, double rate) : model(model), rate(rate) {}

    void getDailyRate(double rate){
        cout << "Car rate: " << rate << endl;
    }

    void displayDetails(){
        cout << "Car model: " << model << endl;
    }
};

class Bike : public Vehicle{
    private:
    string model;
    double rate;

    public:
    Bike(string model, double rate) : model(model), rate(rate) {}

    void getDailyRate(double rate){
        cout << "Bike rate: " << rate << endl;
    }

    void displayDetails(){
        cout << "Bike model: " << model << endl;
    }
};

int main(){
    Car c1("BMW M1", 150000);
    Bike b1("YBR", 200000);
    c1.getDailyRate(150000);
    c1.displayDetails();

    b1.getDailyRate(200000);
    b1.displayDetails();

}
