#include "iostream"
using namespace std;

class SmartDevice{

    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;

};

class LightBulb : public SmartDevice{

    private:
    bool isOn;
    int brightness;

    public:
    LightBulb() : isOn(false), brightness(0) {}

    void turnOn(){
        isOn = true;
        brightness = 100;
        cout << "Bulb turned ON" << endl;
    }

    void turnOff(){
        isOn = false;
        brightness = 0;
        cout << "Bulb turned OFF" << endl;
    }

    void getStatus(){
        cout << "Light Bulb is " << (isOn ? "ON" : "OFF") << ", Brightness: " << brightness << "%\n";
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(20.0) {}

    void turnOn(){
        isOn = true;
        temperature = 22.0;
        cout << "Thermostat turned ON.\n";
    }

    void turnOff(){
        isOn = false;
        cout << "Thermostat turned OFF.\n";
    }

    void getStatus(){
        cout << "Thermostat is " << (isOn ? "ON" : "OFF");
        if (isOn) {
            cout << ", Temperature: " << temperature << "C";
        }
        cout << endl;
    }
};

int main(){
    LightBulb b1;
    Thermostat t1;

    b1.turnOn();
    b1.getStatus();
    b1.turnOff();
    b1.getStatus();
    
    t1.turnOn();
    t1.getStatus();
    t1.turnOff();
    t1.getStatus();
}