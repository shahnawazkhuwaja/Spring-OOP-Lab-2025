#include "iostream"
using namespace std;

class TourGuide {
    string name;
    int experience;
    string specialization;

public:
    TourGuide(string n, int exp, string spec):name(n), experience(exp), specialization(spec){}

    void display() const {
        cout << "Tour Guide: " << name << ", Experience: " << experience << " years, Specialization: " << specialization << endl;
    }
};

class TravelAgency {
    string agencyName;
    TourGuide** guides;
    int capacity;
    int count;

public:
    TravelAgency(string name, int maxGuides):agencyName(name), capacity(maxGuides), count(0) {
        guides = new TourGuide*[capacity];
    }

    void addGuide(string name, int experience, string specialization) {
        if (count<capacity) {
            guides[count]= new TourGuide(name,experience, specialization);
            count++;
        } else {
            cout << "Capacity full!\n";
        }
    }
    void display() const{
        cout << "Travel Agency: " << agencyName << endl;
        cout << "Tour Guides List:\n";
        for (int i =0; i<count; i++) {
            guides[i]->display();
        }
    }

    ~TravelAgency() {
        for (int i=0; i <count; i++) {
            delete guides[i];
        }
        delete[] guides;
    }
};

int main() {
    TravelAgency agency("Khuwaja Travel", 6);

    agency.addGuide("Shahnawaz", 3, "ABC Tours");
    agency.addGuide("Atif", 8, "XYZ Tours");
    agency.addGuide("Aliya", 6, "fgh Tours");
    agency.display();
}