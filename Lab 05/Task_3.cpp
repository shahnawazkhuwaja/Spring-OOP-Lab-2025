#include "iostream"
using namespace std;

class Professor {
    string name;
    string department;

public:
    Professor(string profName, string dept): name(profName), department(dept) {}

    void display() const{
        cout << "Professor: " << name << ", Department: " << department << endl;
    }
};

class University {
    string universityName;
    Professor** professors;
    int capacity;
    int count;

public:
    University(string name, int maxProfessors):universityName(name), capacity(maxProfessors), count(0){
        professors = new Professor*[capacity];
    }

    void addProfessor(string name, string dept) {
        if (count<capacity) {
            professors[count]= new Professor(name, dept);
            count++;
        } else {
            cout << "Capacity full!\n";
        }
    }
    void display() const {
        cout << "University: " << universityName << endl;
        cout << "Professors List:\n";
        for (int i=0; i< count; i++) {
            professors[i]->display();
        }
    }

    ~University() {
        for (int i =0; i< count; i++) {
            delete professors[i];
        }
        delete[] professors;
    }
};

int main() {
    University fast("FAST University", 4);

    fast.addProfessor("Mr. Talha Shahid", "Computer Science");
    fast.addProfessor("Miss Atiya Jokhio", "AI & DS");
    fast.addProfessor("Mr. Shahid Ashraf", "Software Engineering");
    fast.display();
}