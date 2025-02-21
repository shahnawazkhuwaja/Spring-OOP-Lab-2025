#include "iostream"
#include <cstring>
using namespace std;

class Patient {
    int patientID;
    string name;
    int *testResults;
    int numTests;

public:
    Patient(int id, string pname, int tests[], int count) {
        patientID =id;
        name= pname;
        numTests= count;
        testResults = new int[numTests];
        for (int i = 0; i< numTests; i++) {
            testResults[i]=tests[i];
        }
    }
    Patient(const Patient &original) {
        patientID =original.patientID;
        name=original.name;
        numTests =original.numTests;
        testResults= new int[numTests];
        for (int i =0; i<numTests; i++) {
            testResults[i]= original.testResults[i];
        }
    }

    void display() {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Test Results: ";
        for (int i =0; i<numTests; i++) {
            cout << testResults[i] << " ";
        }
        cout << endl;
    }
    ~Patient() {
        delete[] testResults;
    }
};

int main() {
    int testResults1[] = {65, 80, 88};
    Patient p1(123, "Shahnawaz Khuwaja", testResults1, 2);
    cout << "Original Patient:\n";
    p1.display();
    Patient p2 = p1;
    cout << "\nCopied Patient Record:\n";
    p2.display();
}