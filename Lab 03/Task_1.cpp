#include "iostream"
#include <string>
using namespace std;

class MarkerPen {
private:
    string brand, color;
    int inkLevel;
    bool refillable;

public:
    MarkerPen(string b, string c, int ink, bool refill) : brand(b), color(c), inkLevel(ink), refillable(refill) {}

    void write(int usage) {
        if (inkLevel>=usage) {
            inkLevel-=usage;
            cout << "Wrote with the marker. Ink level is now: " << inkLevel << endl;
        } else {
            cout << "Not enough ink to write. Please refill.\n";
        }
    }

    void refill() {
        if (refillable) {
            inkLevel = 100;
            cout << "Marker refilled. Ink level is now: " << inkLevel << endl;
        } else {
            cout << "This marker is not refillable.\n";
        }
    }

    void checkStatus() const {
        cout << "Marker Brand: " << brand << ", Color: " << color << ", Ink Level: " << inkLevel << ", Refillable: " << (refillable ? "Yes" : "No") << endl;
    }
};

int main() {
    MarkerPen marker("Camlin", "Blue", 50, true);
    marker.checkStatus();
    marker.write(30);
    marker.write(30);
    marker.refill();
    marker.write(30);

}
