#include "iostream"
using namespace std;

class Device{

    protected:
    int deviceID;
    bool status;

    public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

    void displayDetails(){
        cout << "------------------------------------" << endl;
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
    }
};

class SmartPhone : virtual public Device{

    protected:
    float screenSize;

    public:
    SmartPhone(int deviceID, bool status, float screenSize) : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails(){
        cout << "Screen Size: " << screenSize << endl;
    }
};

class SmartWatch : virtual public Device{

    protected:
    bool heartRateMonitor;

    public:
    SmartWatch(int deviceID, bool status, bool heartRateMonitor) : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails(){
        cout << "Screen Size: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch{

    private:
    int stepCounter;

    public:
    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter)
                : Device(deviceID, status), SmartPhone(deviceID, status, screenSize),
                  SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}
    
    void displayDetails(){
        Device :: displayDetails();
        SmartPhone :: displayDetails();
        SmartWatch :: displayDetails();
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main(){
    SmartWearable s1(240791, true, 6.4, true, 300);
    s1.displayDetails();
}