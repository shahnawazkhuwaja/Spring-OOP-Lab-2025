#include "iostream"
using namespace std;

class Person {
protected:
    string name, address, phoneNumber, email;
    int id;

public:
    Person(string n, int i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "ID: " << id << "\nName: " << name << "\nAddress: " << address
             << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, int i, string addr, string phone, string mail,
            string courses, double gpa, int year)
        : Person(n, i, addr, phone, mail), coursesEnrolled(courses),
          GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled
             << "\nGPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
private:
    string department, coursesTaught;
    double salary;

public:
    Professor(string n, int i, string addr, string phone, string mail,
              string dept, string courses, double sal)
        : Person(n, i, addr, phone, mail), department(dept),
          coursesTaught(courses), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department
             << "\nCourses Taught: " << coursesTaught
             << "\nSalary: " << salary << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;

public:
    Staff(string n, int i, string addr, string phone, string mail,
          string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept),
          position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department
             << "\nPosition: " << position
             << "\nSalary: $" << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
    Student* registeredStudent;

public:
    Course(string id, string name, int cr, string instr, string sch)
        : courseId(id), courseName(name), credits(cr),
          instructor(instr), schedule(sch), registeredStudent(nullptr) {}

    void registerStudent(Student* student) {
        registeredStudent = student;
    }

    void displayCourseInfo() {
        cout << "Course ID: " << courseId
             << "\nCourse Name: " << courseName
             << "\nCredits: " << credits
             << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << endl;

        if (registeredStudent) {
            cout << "Registered Student:\n";
            registeredStudent->displayInfo();
        } else {
            cout << "No student registered yet.\n";
        }
    }
};

int main() {
    Student stud("Shahnawaz", 123, "abcdef", "12345600", "shahnawaz@abc.com", "CS009, DS008", 3.6, 2022);
    Professor prof("Ahmed", 234, "uvwxyz", "6543210", "ahmed@abc.com", "Computer Science", "CS009", 70000);
    Staff staff("Ali", 432, "lmnopq", "78932300", "ali@abc.com", "Admin", "Clerk", 30000);

    cout << "\nDisplaying Information:\n";
    stud.displayInfo();
    cout << endl;
    prof.displayInfo();
    cout << endl;
    staff.displayInfo();
    cout << endl;
    Course cs009("CS009", "Programming Fundamentals", 2, "Ahmed", "Mon-Tue 11:00 AM");
    cs009.registerStudent(&stud);
    cout << "\nCourse Details:\n";
    cs009.displayCourseInfo();
return 0;
}