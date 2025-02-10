#include "iostream"
#include <string>
using namespace std;

class Planner {
private:
    string tasks[30];

public:
    void addTask(int day, const string& task) {
        if (day < 1 || day > 30) {
            cout << "Invalid day. Please enter a day between 1 and 30.\n";
            return;
        }
        tasks[day - 1] = task;
        cout << "Task added for day " << day << ".\n";
    }

    void updateTask(int day, const string& task) {
        if (day < 1 || day > 30 || tasks[day - 1].empty()) {
            cout << "No task found on this day to update.\n";
            return;
        }
        tasks[day - 1] = task;
        cout << "Task updated for day " << day << ".\n";
    }

    void displayTasks() const {
        cout << "Planner Tasks:\n";
        bool hasTasks = false;
        for (int i = 0; i < 30; ++i) {
            if (!tasks[i].empty()) {
                cout << "Day " << (i + 1) << ": " << tasks[i] << endl;
                hasTasks = true;
            }
        }
        if (!hasTasks) {
            cout << "No tasks scheduled.\n";
        }
    }
};

int main() {
    Planner planner;

    planner.addTask(1, "Book venue for wedding.");
    planner.addTask(15, "Meet with client for menu planning.");
    planner.displayTasks();
    planner.updateTask(15, "Meet with client for menu confirmation.");
    planner.displayTasks();

}
