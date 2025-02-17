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
    ~Book() {
        cout << "Destroying book: " << title << endl;
        delete[] title;
    }

    void display() const {
        cout << "Title: " << title << ", Price: $" << price << ", Stock: " << stock << endl;
    }
};

int main() {
    Book book1("ABCDEFG", 55.0, 5);
    book1.display();
}