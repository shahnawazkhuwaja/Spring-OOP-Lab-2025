#include "iostream"
using namespace std;

class Person{

    protected:
    string name;
    int age;

    public:
    Person(string name, int age) : name(name), age(age) {}

    void displayDetails(){
        cout << "---------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person{

    protected:
    string subject;

    public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}

    void displayDetails(){
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : virtual public Person{

    protected:
    string researchArea;

    public:
    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails(){
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher{

    private:
    int publications;

    public:
    Professor(string name, int age, string subject, string researchArea, int publications)
            : Person(name, age), Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}
    
    void displayDetails(){
        Person :: displayDetails();
        Teacher :: displayDetails();
        Researcher :: displayDetails();
        cout << "Publications: " << publications << endl;
    }
};

int main(){
    Professor p1("Shahnawaz Khuwaja", 28, "OOP", "Lab 7", 2016);
    p1.displayDetails();
}