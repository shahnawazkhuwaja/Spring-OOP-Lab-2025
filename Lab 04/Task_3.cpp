#include "iostream"
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    double price;
    int stock;

public:
    Book(const char* t, double p, int s) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        price = p;
        stock = s;
    }
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        price = other.price;
        stock = other.stock;
    }

    ~Book() {
        cout << "Destroying book: " << title << endl;
        delete[] title;
    }

    void updateDetails(const char* newTitle, double newPrice) {
        delete[] title;
        title = new char[strlen(newTitle) + 1];
        strcpy(title, newTitle);
        price = newPrice;
    }

    void display() const {
        cout << "Title: " << title << ", Price: $" << price << ", Stock: " << stock << endl;
    }
};

int main() {
    Book book3("Data Structures", 50.0, 10);
    book3.display();

    Book book4 = book3;
    book4.display();
    book3.updateDetails("shsh", 60.0);
    book3.display();
    book4.display();
}