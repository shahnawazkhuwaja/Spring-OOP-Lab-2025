#include "iostream"
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity {
private:
    double distance;
    double time;

public:
    Running(double d, double t) {
        distance = d;
        time = t;
    }

    double calculateCaloriesBurned(){
        return distance * 60;
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;

public:
    Cycling(double s, double t) {
        speed = s;
        time = t;
    }

    double calculateCaloriesBurned(){
        return speed * time * 30;
    }
};

int main() {
    Running run(5.0, 30);
    Cycling cycle(20.0, 1.0);
    cout << "Calories burned while running: " << run.calculateCaloriesBurned() << " kcal" << endl;
    cout << "Calories burned while cycling: " << cycle.calculateCaloriesBurned() << " kcal" << endl;

return 0;
}